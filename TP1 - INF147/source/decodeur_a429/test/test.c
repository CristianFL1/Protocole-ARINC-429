#include "configuration.h"
#include "utilitaire.h"
#include "decodeur_a429.h"

#include <stdio.h>

#if(TEST)

/*
	AFFICHER_ENTETE_TEST

	Cette fonction affiche l'entête du programme principal
	lorsqu'il est exécuté en mode test.

	PARAMÈTRES :
		- AUCUN

	RETOUR :
		- AUCUN
*/
void afficher_entete_test();

int main(void)
{

	/****************************************
	* Affichage de l'entête de TEST
	*****************************************/

	afficher_entete_test();

	/****************************************
	* Test de la fonction AFFICHER_HEURE
	*****************************************/

	printf("*********************************\n");
	printf("* TEST AFFICHER_HEURE\n");
	printf("*********************************\n");

	printf("\nAffichage d'heure avec 0 seconde\n");
	printf("Valeur attendue : 00h00m00s\n");
	printf("Valeur obtenue  : ");
	afficher_heure(0);
	printf("\n");

	printf("\nAffichage d'heure avec 59 seconde\n");
	printf("Valeur attendue : 00h00m59s\n");
	printf("Valeur obtenue  : ");
	afficher_heure(59);
	printf("\n");

	printf("\nAffichage d'heure avec 61 seconde\n");
	printf("Valeur attendue : 00h01m01s\n");
	printf("Valeur obtenue  : ");
	afficher_heure(61);
	printf("\n");

	printf("\nAffichage d'heure avec 3661 seconde\n");
	printf("Valeur attendue : 01h01m01s\n");
	printf("Valeur obtenue  : ");
	afficher_heure(3661);
	printf("\n");

	printf("\nAffichage d'heure avec 32949 seconde\n");
	printf("Valeur attendue : 09h09m09s\n");
	printf("Valeur obtenue  : ");
	afficher_heure(32949);
	printf("\n");

	printf("\nAffichage d'heure avec 86399 seconde\n");
	printf("Valeur attendue : 23h59m59s\n");
	printf("Valeur obtenue  : ");
	afficher_heure(86399);
	printf("\n");

	/****************************************
	* Test de la fonction DECIMAL_A_OCTALE
	*****************************************/

	printf("\n*********************************\n");
	printf("* TEST DECIMAL_A_OCTALE\n");
	printf("*********************************\n");

	printf("\nConverstion de la valeur 1\n");
	printf("Valeur attendue : 1\n");
	printf("Valeur obtenue  : %i\n", decimale_a_octale(1));

	printf("\nConverstion de la valeur 8\n");
	printf("Valeur attendue : 10\n");
	printf("Valeur obtenue  : %i\n", decimale_a_octale(8));

	printf("\nConverstion de la valeur 15\n");
	printf("Valeur attendue : 17\n");
	printf("Valeur obtenue  : %i\n", decimale_a_octale(15));

	printf("\nConverstion de la valeur 64\n");
	printf("Valeur attendue : 100\n");
	printf("Valeur obtenue  : %i\n", decimale_a_octale(64));

	printf("\nConverstion de la valeur 104\n");
	printf("Valeur attendue : 150\n");
	printf("Valeur obtenue  : %i\n", decimale_a_octale(104));

	printf("\nConverstion de la valeur 209\n");
	printf("Valeur attendue : 321\n");
	printf("Valeur obtenue  : %i\n", decimale_a_octale(209));
	printf("\n");

	/*********************************************
	* Test de la fonction CALCULER_NB_BITS_ACTIFS
	**********************************************/

	printf("\n*********************************\n");
	printf("* TEST CALCULER_NB_BITS_ACTIFS\n");
	printf("*********************************\n");

	printf("\nCalcul du nombre de bits actif dans la valeur 0x00000000\n");
	printf("Valeur attendue : 0\n");
	printf("Valeur obtenue  : %i\n", calculer_nb_bits_actifs(0x00000000));
	
	printf("\nCalcul du nombre de bits actif dans la valeur 0x00000001\n");
	printf("Valeur attendue : 1\n");
	printf("Valeur obtenue  : %i\n", calculer_nb_bits_actifs(0x00000001));

	printf("\nCalcul du nombre de bits actif dans la valeur 0x80000000\n");
	printf("Valeur attendue : 1\n");
	printf("Valeur obtenue  : %i\n", calculer_nb_bits_actifs(0x80000000));

	printf("\nCalcul du nombre de bits actif dans la valeur 0x12345678\n");
	printf("Valeur attendue : 13\n");
	printf("Valeur obtenue  : %i\n", calculer_nb_bits_actifs(0x12345678));

	printf("\nCalcul du nombre de bits actif dans la valeur 0xFFFFFFFF\n");
	printf("Valeur attendue : 32\n");
	printf("Valeur obtenue  : %i\n", calculer_nb_bits_actifs(0xFFFFFFFF));
	printf("\n");

	/****************************************
	* Test de la fonction AFFICHER_BITS
	*****************************************/

	printf("\n*********************************\n");
	printf("* TEST AFFICHER_BITS\n");
	printf("*********************************\n");

	printf("\nAffichage des bits de la valeur 0x12345678\n");
	printf("Valeur attendue : (0x12345678) : 0001 0010 0011 0100 0101 0110 0111 1000\n");
	printf("Valeur obtenue  : ");
	afficher_bits(0x12345678, 0, 31);
	printf("\n");

	printf("\nAffichage des bits de la valeur 0x9ABCBEF0\n");
	printf("Valeur attendue : (0x9ABCBEF0) : 1001 1010 1011 1100 1101 1110 1111 0000\n");
	printf("Valeur obtenue  : ");
	afficher_bits(0x9ABCBEF0, 0, 31);
	printf("\n");

	printf("\nAffichage des bits de la valeur 0xA3CF8643\n");
	printf("Valeur attendue : (0xA3CF8643) : 1000 0110 0100\n");
	printf("Valeur obtenue  : ");
	afficher_bits(0xA3CF8643, 4, 15);
	printf("\n");

	printf("\nAffichage des bits de la valeur 0xA3CF8643\n");
	printf("Valeur attendue : (0xA3CF8643) : 1\n");
	printf("Valeur obtenue  : ");
	afficher_bits(0xA3CF8643, 31, 31);
	printf("\n");

	printf("\nAffichage des bits de la valeur 0xA3CF8643\n");
	printf("Valeur attendue : (0xA3CF8643) : 1\n");
	printf("Valeur obtenue  : ");
	afficher_bits(0xA3CF8643, 0, 0);
	printf("\n");

	/****************************************
	* Test de la fonction DECODER_MOT_A429
	*****************************************/

	printf("\n*********************************\n");
	printf("*TEST DECODER_MOT_A429\n");
	printf("*********************************\n");

	int corruption   = 0;				// État de corrupion du mot (0 ou 1)
	int num_mot		 = 0;				// Numéro du mot (150, 232, 252, 255, 260, 310 ou 311)
	double mot_BNR   = 0.0;				// Le mot de type BNR
	int donnee1_BCD  = 0;			// 1ere donnée du mot BCD
	int donnee2_BCD  = 0;			// 2eme donnée du mot BCD
	int donnee3_BCD  = 0;			// 3eme donnée du mot BCD
	int donnee4_BCD  = 0;			// 4eme donnée du mot BCD

	decoder_mot_a429(0x85D3029A, &corruption, &num_mot, &mot_BNR, &donnee1_BCD, &donnee2_BCD, &donnee3_BCD, &donnee4_BCD);

	printf("\nDécodage du mot 0x85D3029A\n");
	printf("Valeurs attendues : \n");
	printf("  - Est corrumpu : 0\n");
	printf("  - Numero mot   : 232\n");
	printf("  - Donne_bnr    : 0\n");
	printf("  - Donne_bcd1   : 2\n");
	printf("  - Donne_bcd2   : 24\n");
	printf("  - Donne_bcd3   : 20\n");
	printf("  - Donne_bcd4   : 11\n");
	printf("\nValeurs obtenues  : \n");
	printf("  - Est corrumpu : %i\n", corruption);
	printf("  - Numero mot   : %i\n", num_mot);
	printf("  - Donne_bnr    : %lf\n", mot_BNR);
	printf("  - Donne_bcd1   : %i\n", donnee1_BCD);
	printf("  - Donne_bcd2   : %i\n", donnee2_BCD);
	printf("  - Donne_bcd3   : %i\n", donnee3_BCD);
	printf("  - Donne_bcd4   : %i\n", donnee4_BCD);
	printf("\n");

	// Remise à zéro des valeurs
	corruption  = 0;
	num_mot     = 0;
	mot_BNR     = 0.0;
	donnee1_BCD = 0;
	donnee2_BCD = 0;
	donnee3_BCD = 0;
	donnee4_BCD = 0;

	decoder_mot_a429(0x003C90B0, &corruption, &num_mot, &mot_BNR, &donnee1_BCD, &donnee2_BCD, &donnee3_BCD, &donnee4_BCD);

	printf("\nDécodage du mot 0x85D3029A\n");
	printf("Valeurs attendues : \n");
	printf("  - Est corrumpu : 0\n");
	printf("  - Numero mot   : 260\n");
	printf("  - Donne_bnr    : 0\n");
	printf("  - Donne_bcd1   : 16\n");
	printf("  - Donne_bcd2   : 4\n");
	printf("  - Donne_bcd3   : 15\n");
	printf("  - Donne_bcd4   : 0\n");
	printf("\nValeurs obtenues  : \n");
	printf("  - Est corrumpu : %i\n", corruption);
	printf("  - Numero mot   : %i\n", num_mot);
	printf("  - Donne_bnr    : %lf\n", mot_BNR);
	printf("  - Donne_bcd1   : %i\n", donnee1_BCD);
	printf("  - Donne_bcd2   : %i\n", donnee2_BCD);
	printf("  - Donne_bcd3   : %i\n", donnee3_BCD);
	printf("  - Donne_bcd4   : %i\n", donnee4_BCD);
	printf("\n");

	// Remise à zéro des valeurs
	corruption = 0;
	num_mot = 0;
	mot_BNR = 0.0;
	donnee1_BCD = 0;
	donnee2_BCD = 0;
	donnee3_BCD = 0;
	donnee4_BCD = 0;

	decoder_mot_a429(0x812EAF68, &corruption, &num_mot, &mot_BNR, &donnee1_BCD, &donnee2_BCD, &donnee3_BCD, &donnee4_BCD);

	printf("\nDécodage du mot 0x812EAF68\n");
	printf("Valeurs attendues : \n");
	printf("  - Est corrumpu : 0\n");
	printf("  - Numero mot   : 150\n");
	printf("  - Donne_bnr    : 77487.000000\n");
	printf("  - Donne_bcd1   : 0\n");
	printf("  - Donne_bcd2   : 0\n");
	printf("  - Donne_bcd3   : 0\n");
	printf("  - Donne_bcd4   : 0\n");
	printf("\nValeurs obtenues  : \n");
	printf("  - Est corrumpu : %i\n", corruption);
	printf("  - Numero mot   : %i\n", num_mot);
	printf("  - Donne_bnr    : %lf\n", mot_BNR);
	printf("  - Donne_bcd1   : %i\n", donnee1_BCD);
	printf("  - Donne_bcd2   : %i\n", donnee2_BCD);
	printf("  - Donne_bcd3   : %i\n", donnee3_BCD);
	printf("  - Donne_bcd4   : %i\n", donnee4_BCD);
	printf("\n");

	// Remise à zéro des valeurs
	corruption = 0;
	num_mot = 0;
	mot_BNR = 0.0;
	donnee1_BCD = 0;
	donnee2_BCD = 0;
	donnee3_BCD = 0;
	donnee4_BCD = 0;

	decoder_mot_a429(0x83D2E3C8, &corruption, &num_mot, &mot_BNR, &donnee1_BCD, &donnee2_BCD, &donnee3_BCD, &donnee4_BCD);

	printf("\nDécodage du mot 0x83D2E3C8\n");
	printf("Valeurs attendues : \n");
	printf("  - Est corrumpu : 0\n");
	printf("  - Numero mot   : 310\n");
	printf("  - Donne_bnr    : 43.102340\n");
	printf("  - Donne_bcd1   : 0\n");
	printf("  - Donne_bcd2   : 0\n");
	printf("  - Donne_bcd3   : 0\n");
	printf("  - Donne_bcd4   : 0\n");
	printf("\nValeurs obtenues  : \n");
	printf("  - Est corrumpu : %i\n", corruption);
	printf("  - Numero mot   : %i\n", num_mot);
	printf("  - Donne_bnr    : %lf\n", mot_BNR);
	printf("  - Donne_bcd1   : %i\n", donnee1_BCD);
	printf("  - Donne_bcd2   : %i\n", donnee2_BCD);
	printf("  - Donne_bcd3   : %i\n", donnee3_BCD);
	printf("  - Donne_bcd4   : %i\n", donnee4_BCD);
	printf("\n");

	// Remise à zéro des valeurs
	corruption = 0;
	num_mot = 0;
	mot_BNR = 0.0;
	donnee1_BCD = 0;
	donnee2_BCD = 0;
	donnee3_BCD = 0;
	donnee4_BCD = 0;

	decoder_mot_a429(0x00261AAA, &corruption, &num_mot, &mot_BNR, &donnee1_BCD, &donnee2_BCD, &donnee3_BCD, &donnee4_BCD);

	printf("\nDécodage du mot 0x00261AAA\n");
	printf("Valeurs attendues : \n");
	printf("  - Est corrumpu : 1\n");
	printf("  - Numero mot   : 252\n");
	printf("  - Donne_bnr    : 9754.000000\n");
	printf("  - Donne_bcd1   : 0\n");
	printf("  - Donne_bcd2   : 0\n");
	printf("  - Donne_bcd3   : 0\n");
	printf("  - Donne_bcd4   : 0\n");
	printf("\nValeurs obtenues  : \n");
	printf("  - Est corrumpu : %i\n", corruption);
	printf("  - Numero mot   : %i\n", num_mot);
	printf("  - Donne_bnr    : %lf\n", mot_BNR);
	printf("  - Donne_bcd1   : %i\n", donnee1_BCD);
	printf("  - Donne_bcd2   : %i\n", donnee2_BCD);
	printf("  - Donne_bcd3   : %i\n", donnee3_BCD);
	printf("  - Donne_bcd4   : %i\n", donnee4_BCD);
	printf("\n");	

	/****************************************
	* Test de la fonction AFFICHER_MOT_A429
	*****************************************/

	printf("\n*********************************\n");
	printf("* TEST AFFICHER_MOT_A429\n");
	printf("*********************************\n");

	printf("\nAffichage du mot 0x811C6268 (Heure du vol)\n");
	printf("Valeur attendue : 20h13m22s\n");
	printf("Valeur obtenue  : ");
	afficher_mot_a429(0x811C6268);
	printf("\n");

	printf("\nAffichage du mot 0x85D3029A (Départ de l'aéroport)\n");
	printf("Valeur attendue : CYUL\n");
	printf("Valeur obtenue  : ");
	afficher_mot_a429(0x85D3029A);
	printf("\n");

	printf("\nAffichage du mot 0x8001ABAA (Altitude)\n");
	printf("Valeur attendue : 427.0\n");
	printf("Valeur obtenue  : ");
	afficher_mot_a429(0x8001ABAA);
	printf("\n");

	printf("\nAffichage du mot 0x81C5CAAD (Arrivé à l'aéroport)\n");
	printf("Valeur attendue : KORD\n");
	printf("Valeur obtenue  : ");
	afficher_mot_a429(0x81C5CAAD);
	printf("\n");

	printf("\nAffichage du mot 0x003C90B0 (Date du vol)\n");
	printf("Valeur attendue : 15/4/16\n");
	printf("Valeur obtenue  : ");
	afficher_mot_a429(0x003C90B0);
	printf("\n");

	printf("\nAffichage du mot 0x840834C8 (Latitude)\n");
	printf("Valeur attendue : 45.449968\n");
	printf("Valeur obtenue  : ");
	afficher_mot_a429(0x840834C8);
	printf("\n");

	printf("\nAffichage du mot 0x668D91C9 (Longitude)\n");
	printf("Valeur attendue : -77.099860\n");
	printf("Valeur obtenue  : ");
	afficher_mot_a429(0x668D91C9);
	printf("\n");

	return 0;
}

//
// Affiche l'entête du mode TEST
//
void afficher_entete_test() {
	printf("******************************\n*");
	printf("DECODEUR ARINC-429 :: Mode Test\n*\n");
	printf("*Auteur  : Cristian Fermin Lopez\n");
	printf("*Session : Été 2022\n*");
	printf("******************************\n\n");
}


#endif