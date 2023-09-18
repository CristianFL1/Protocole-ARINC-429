/****************************************************************************************
/*                                      UTILITAIRE.C                                    *
/****************************************************************************************
	Auteur : Cristian Fermin Lopez
	Date   : 12 juin 2022

	Liste des fonctions publiques:

	  - afficher_heure           : Affiche l'heure avec le format suivant : 00h00m00s.
	  - decimale_a_octale        : Convertie un nombre interprété à base décimale
								   en un nombre interprété à base octale.
	  - calculer_nb_bits_actifs  : Calcule le nombre de bit actif (1) dans une valeur donnée
	  - afficher_bits            : Affiche une valeur donnée en base 2

*****************************************************************************************/
#include "utilitaire.h"

#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

/****************************************************************************************
*                           DÉFINTION DES TYPES ET CONSTANTES                           *
****************************************************************************************/

// Nombre de seconde dans 1 heure
#define NB_SEC_HEURE		3600

// Nombre de seconde dans 1 minute
#define NB_SEC_MINUTES		60

// Constante utilisée pour convertir une valeur de base 10 à base 8
#define BASE_OCTALE			8

// Constante utilisée pour reconstituer la valeur
#define BASE_DECIMAL		10

/****************************************************************************************
*                           DÉFINTION DES FONCTIONS PUBLIQUES                           *
****************************************************************************************/

//
// Cette fonction permet d'afficher l'heure selon le format suivant : 00h00m00s
//
void afficher_heure(unsigned int seconde) {
	int reste;
	int nb_heure;
	int nb_minute;
	int nb_seconde;

	// Calcule le nombre d'heure avec le nombre de seconde donnée
	nb_heure = seconde / NB_SEC_HEURE;
	reste = seconde % NB_SEC_HEURE;

	// Calcule le nombre de minute avec le nombre de seconde donnée
	nb_minute = reste / NB_SEC_MINUTES;
	reste = reste % NB_SEC_MINUTES; 

	// Le nombre de seconde restant
	nb_seconde = reste;

	printf("%ih%im%is", nb_heure, nb_minute, nb_seconde);
}

//
// Cette fonction convertie un nombre interprété à base décimale 
// en un nombre interprété à base octale.
//
unsigned int decimale_a_octale(unsigned int decimal) {
	int i = 0;				// Poids de la position du nombre en decimal
	int conv_octal = 0;		// Le nombre convertit en base octale

	// On multiplie le reste de la division du nombre decimal par le poids de la decimal
	// ensuite on divise la decimal par 8 
	while (decimal != 0) {
		conv_octal += decimal % BASE_OCTALE * pow(BASE_DECIMAL, i);
		decimal /= BASE_OCTALE;
		i++;
	}
	return conv_octal;
}

//
// Cette fonction permet de calculer le nombre de bit actif dans une valeur donnée
//
unsigned int calculer_nb_bits_actifs(unsigned int valeur) {
	unsigned int masque;		// Masque pour faire des opérations avec les bit de la valeur passée en paramètre
	unsigned int valeur_bit;	// Permet de savoir si la valeur du bit est 0 ou 1
	int nb_bit = 0;				// Nombre de bit actif dans la valeur passée en paramètre

	// On parcours la valeur passée en paramètre du bit le moins significatif au bit le plus significatif 
	// On crée un masque pour lequel on envoi un bit actif à la position voulu pour pouvoir récupérer
	// le bit. 
	//
	// Si le bit récupéré est actif alors on incrément la variable nb_bit de 1, ce qui permet de savoir
	// combien de bit sont actif dans la valeur
	for (int i = 0; i < 32; i++)
	{
		masque = 1 << i;
		valeur_bit = (valeur & masque) >> i;
		if (valeur_bit == 1) {
			nb_bit++;
		}
	}

	return nb_bit;
}

//
// Cette fonction permet d'afficher les bits d'une valeur donnée selon
// une intervalle
//
void afficher_bits(unsigned int valeur_afficher, int ls_bit, int ms_bit) {
	unsigned int masque;		// Masque pour faire des opérations avec les bit de la valeur passée en paramètre
	unsigned int valeur_bit;	// Permet de savoir si la valeur du bit est 0 ou 1

	int nb_zero = 0;			// Nombre de bit desactivé dans la valeur passée en paramètre
								// Pour savoir combien d'espace ajouter pour l'affichage
								// Exemple -> on veut afficher 0x  3c90b0 au lieu de 0x003c90b0

	printf("(0x");			// Affiche la première partie de la donnée " (0x "
	

	// On parcours la valeur passée en paramètre du bit le plus significatif au bit le moins significatif 
	// On compte le nombre de 0 qu'il y a avant le premier bit actif pour les remplacer par des espaces
	// *les 0 sont remplacés par des espaces seulement lorsque la suite suivante est trouvé : 0000*
	for (int i = ms_bit; i > ls_bit; i--)
	{
		masque = 1 << i;
		valeur_bit = ((valeur_afficher ^ masque) >> i);
		
		if (valeur_bit == 1) {
			nb_zero++;
			if (nb_zero == 4) {
				printf(" ");
				nb_zero = 0;
			}
		}
		else {
			i = ls_bit;
		}
	}
	
	printf("%x) : ", valeur_afficher);	// Affiche la deuxième partie du message " 0x  3c90b0 : "
	
	// On parcours la valeur passée en paramètre du bit le plus significatif au bit le moins significatif 
	// lorsqu'il y a 4 zéro d'affiler un ajoute un espace à droite
	for (int i = ms_bit; i >= ls_bit; i--)
	{
		masque = 1 << i;
		valeur_bit = (valeur_afficher & masque) >> i;

		if(!(i % 4))
			printf("%i ", valeur_bit);
		else
			printf("%i", valeur_bit);
		
	}

	printf("\n");
}