/****************************************************************************************
/*                                      DECODEUR_A429.C                                 *
/****************************************************************************************
	Auteur : Cristian Fermin Lopez
	Date   : 12 juin 2022

	Liste des fonctions publiques:

	  - afficher_entete_decodeur : Affiche l'ent�te du programme en mode application
	  - afficher_mot_a429        :
	  - decoder_mot_a429         :

*****************************************************************************************/
#include "decodeur_a429.h"
#include "utilitaire.h"
#include "icd.h"

#include <stdio.h>

/****************************************************************************************
*                           D�FINTION DES TYPES ET CONSTANTES                           *
****************************************************************************************/


/****************************************************************************************
*                           D�FINTION DES FONCTIONS PUBLIQUES                           *
****************************************************************************************/

//
// Cette fonction affiche l'ent�te du programme en mode application
//
void afficher_entete_decodeur() {
	printf("******************************\n*");
	printf("DECODEUR ARINC-429\n*\n");
	printf("*Auteur  : Cristian Fermin Lopez\n");
	printf("*Session : �t� 2022\n*");
	printf("******************************\n\n");

	printf("Mot ARINC-429 | Est Corrompu | Donnee\n");
	printf("--------------|--------------|--------------------------------");
}

//
// Cette fonction affiche le mot d�cod� selon le protocole A429
//
void afficher_mot_a429(unsigned int mot_ARINC429) {
	unsigned int masque;		// Masque pour faire des op�rations avec les bit de la valeur pass�e en param�tre
	unsigned int valeur_bit;	// Permet de savoir si la valeur du bit est 0 ou 1

	int nb_zero = 0;			// Nombre de bit desactiv� dans la valeur pass�e en param�tre
								// Pour savoir combien d'espace ajouter pour l'affichage
								// Exemple -> on veut afficher 0x  3c90b0 au lieu de 0x003c90b0

	int corruption;				// �tat de corrupion du mot (0 ou 1)
	int num_mot;				// Num�ro du mot (150, 232, 252, 255, 260, 310 ou 311)
	double mot_BNR;				// Le mot de type BNR
	int donnee1_BCD;			// 1ere donn�e du mot BCD
	int donnee2_BCD;			// 2eme donn�e du mot BCD
	int donnee3_BCD;			// 3eme donn�e du mot BCD
	int donnee4_BCD;			// 4eme donn�e du mot BCD

	printf("\n0x");				// Affiche la premi�re partie de la donn�e " (0x "

	// On parcours la valeur pass�e en param�tre du bit le plus significatif au bit le moins significatif 
	// On compte le nombre de 0 qu'il y a avant le premier bit actif pour les remplacer par des espaces
	// *les 0 sont remplac�s par des espaces seulement lorsque la suite suivante est trouv� : 0000*
	for (int i = 31; i > 0; i--)
	{
		masque = 1 << i;
		valeur_bit = ((mot_ARINC429 ^ masque) >> i);

		if (valeur_bit == 1) {
			nb_zero++;
			if (nb_zero == 4) {
				printf(" ");
				nb_zero = 0;
			}
		}
		else {
			i = 0;
		}
	}

	printf("%x    |", mot_ARINC429);		// Affiche la deuxi�me partie du message " 0x  3c90b0    |"

	// On utilise cette fonction pour d�coder le mot encod� sous le protocole ARINC429
	decoder_mot_a429(mot_ARINC429, &corruption, &num_mot, &mot_BNR, &donnee1_BCD, &donnee2_BCD, &donnee3_BCD, &donnee4_BCD);

	printf("          ");					// Affiche des espaces (pour la lisibilit�)

	// Affiche "oui" lorsque le mot est corrompu et des espaces lorsqu'il ne l'est pas
	if (corruption == 1) {
		printf("oui");
	}
	else {
		printf("   ");
	}

	printf(" |");							// Affiche une barre (pour la lisibilit�)

	// On analyse le num�ro du mot pour savoir qu'elle information il encode
	//
	// Le numero 150 encode l'heure du vol
	if (num_mot == NUMERO_MOT_UTC) {
		printf(" Heure du vol         : ");
		afficher_heure(mot_BNR);
	}
	// Le numero 232 encode l'a�roport de d�part
	else if (num_mot == NUMERO_MOT_DEPART){
		printf(" Depart de l'aeroport : ");
		printf("%c%c%c%c", donnee1_BCD + 'A', donnee2_BCD + 'A', donnee3_BCD + 'A', donnee4_BCD + 'A');		
	}
	// Le numero 252 encode l'altitude de l'appareil
	else if (num_mot == NUMERO_MOT_ALTITUDE){
		printf(" Altitude             : ");
		printf("%.1lf", mot_BNR);
		printf("\n              |              |");
	}
	// Le numero 255 encode l'a�roport d'arriv�e
	else if (num_mot == NUMERO_MOT_DESTINATION){
		printf(" Arrive a l'aeroport  : ");
		printf("%c%c%c%c", donnee1_BCD + 'A', donnee2_BCD + 'A', donnee3_BCD + 'A', donnee4_BCD + 'A');
	}
	// Le numero 260 encode la date du vol
	else if (num_mot == NUMERO_MOT_DATE){
		printf(" Date du vol          : ");

		// Si la 4 ieme donn�e du mot est 0, on ne l'affiche pas
		// Cela permet d'afficher 12/4/16 au lieu de 15/04/16
		if (donnee4_BCD == 0)
			printf("%i/%i/%i", donnee3_BCD, donnee2_BCD, donnee1_BCD);
		else
			printf("%i/%i%i/%i", donnee3_BCD, donnee4_BCD, donnee2_BCD, donnee1_BCD);
		printf("\n              |              |");
	}
	// Le numero 310 encode la latitude de l'appareil
	else if (num_mot == NUMERO_MOT_LATITUDE){
		printf(" Latitude             : ");
		printf("%lf", mot_BNR);
	}
	// Le numero 311 encode la longitude de l'appareil
	else if (num_mot == NUMERO_MOT_LONGITUDE){
		printf(" Longitude            : ");
		printf("%lf", mot_BNR);
	}
}

//
// Cette fonction permet de d�cod� un mot qui est encod�
// avec le protocole ARINC 429
//
void decoder_mot_a429(unsigned int mot_ARINC429, int* etat_corruption, int* num_mot, double* mot_BNR, int* donnee1_BCD, int* donnee2_BCD, int* donnee3_BCD, int* donnee4_BCD) {
	unsigned int masque;			// Masque pour faire des op�rations avec les bit de la valeur pass�e en param�tre
	unsigned int resultat;			// Entrepose le resultat du calcul binaire entre le masque et le mot_ARINC429

	// On extrait le num�ro du mot et on le convertie en base octale
	masque = 0b11111111 << 0;
	*num_mot = decimale_a_octale(masque & mot_ARINC429);
	
	// Si le num�ro du mot est 232, 255 ou 260 alors on extrait les bits des 4 diff�rentes donn�es 
	if (*num_mot == NUMERO_MOT_DEPART || *num_mot == NUMERO_MOT_DESTINATION || *num_mot == NUMERO_MOT_DATE) {
		masque = 0b00011111 << 8;
		resultat = masque & mot_ARINC429;
		*donnee1_BCD = resultat >> 8;

		masque = 0b00011111 << 13;
		resultat = masque & mot_ARINC429;
		*donnee2_BCD = resultat >> 13;

		masque = 0b00011111 << 18;
		resultat = masque & mot_ARINC429;
		*donnee3_BCD = resultat >> 18;

		masque = 0b00111111 << 23;
		resultat = masque & mot_ARINC429;
		*donnee4_BCD = resultat >> 23;
	}
	// Si le num�ro du mot est 150, 252, 310 ou 311 alors on d�code le mot gr�ce � la r�solution appropri�e
	else if (*num_mot == NUMERO_MOT_UTC || *num_mot == NUMERO_MOT_ALTITUDE || *num_mot == NUMERO_MOT_LATITUDE || *num_mot == NUMERO_MOT_LONGITUDE) {
		// on extrait le mot BNR encod�
		masque = 0b000111111111111111111111 << 8;
		resultat = masque & mot_ARINC429;

		*mot_BNR = resultat >> 8;

		// Si le num�ro du mot est 150, on le multiplie par la r�solution du mot UTC
		if(*num_mot == NUMERO_MOT_UTC)
			*mot_BNR *= RESOLUTION_MOT_UTC;
		// Si le num�ro du mot est 252, on le multiplie par la r�solution du mot UTC
		else if(*num_mot == NUMERO_MOT_ALTITUDE)
			*mot_BNR *= RESOLUTION_MOT_ALTITUDE;
		// Si le num�ro du mot est 310, on le multiplie par la r�solution du mot UTC
		else if(*num_mot == NUMERO_MOT_LATITUDE)
			*mot_BNR *= RESOLUTION_MOT_LATITUDE;
		// Si le num�ro du mot est 311, on le multiplie par la r�solution du mot UTC
		else if (*num_mot == NUMERO_MOT_LONGITUDE){
			*mot_BNR *= RESOLUTION_MOT_LONGITUDE;

			// On extrait les bits de signe du mot
			masque = 0b11 << 29;
			resultat = (masque & mot_ARINC429) >> 29;
			
			// Si les 2 bits de signe sont � 1 alors on multiplie par -1
			// pour le transformer en nombre n�gatif
			if (resultat == 0b11) {
				*mot_BNR *= -1;
			}
		}
	}
	
	// Si le nombre de bits actifs est impair alor l'�tat de corruption est 0, sinon il est � 1
	if((calculer_nb_bits_actifs(mot_ARINC429) % 2) != 0 )
		*etat_corruption = 0;
	else
		*etat_corruption = 1;
}