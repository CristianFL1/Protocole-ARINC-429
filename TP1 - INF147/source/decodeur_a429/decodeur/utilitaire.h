/****************************************************************************************
/*                                      UTILITAIRE.H                                    *
/****************************************************************************************
    Auteur : Cristian Fermin Lopez
    Date   : 12 juin 2022

    Liste des fonctions publiques:

      - afficher_heure           : Affiche l'heure avec le format suivant : 00h00m00s.
      - decimale_a_octale        : Convertie un nombre interpr�t� � base d�cimale
                                   en un nombre interpr�t� � base octale.
      - calculer_nb_bits_actifs  : Calcule le nombre de bit actif (1) dans une valeur donn�e
      - afficher_bits            : Affiche une valeur donn�e en base 2

*****************************************************************************************/
#ifndef __A429_UTILITAIRE__ 
#define __A429_UTILITAIRE__



/****************************************************************************************
*                           D�FINTION DES TYPES ET CONSTANTES                           *
****************************************************************************************/


/****************************************************************************************
*                       D�CLARATION DES FONCTIONS PUBLIQUES                             *
****************************************************************************************/

/*
    AFFICHER_HEURE

    Cette fonction permet d'afficher l'heure en fonction du nombre
    de seconde donn� avec le format suivant : 00h00m00s

    PARAM�TRES :
        - seconde : Le nombre de seconde � convertir selon format

    RETOUR :
        - AUCUN
*/
void afficher_heure(unsigned int seconde);

/*
    DECIMALE_A_OCTALE

    Cette fonction convertie un nombre interpr�t� � base d�cimale
    en un nombre interpr�t� � base octale.

    PARAM�TRES :
        - decimal : Le nombre interpr�t� en base 10

    RETOUR :
        - Le nombre interpr�t� en base 8
*/
unsigned int decimale_a_octale(unsigned int decimal);

/*
    CALCULER_NB_BITS_ACTIFS

    Cette fonction permet de calculer le nombre de bit actif
    dans une valeur donn�e. La fonctione est principalement utilis�e
    pour savoir si la valeur donn�e est de parit� pair ou impair

    PARAM�TRES :
        - valeur : La valeur pour laquelle on veut calculer le nombre de bit actif

    RETOUR :
        - Le nombre de bit actif
*/
unsigned int calculer_nb_bits_actifs(unsigned int valeur);

/*
    AFFICHER_BITS

    
    Cette fonction permet d'afficher une valeur donn� en base 2.
    L'intervalle des bits � afficher doit �tre pr�cis� avec les deux
    param�tres (ls_bit et ms_bit).

    PARAM�TRES :
        - valeur_afficher : La valeur pour laquelle on veut afficher les bits
        - ls_bit          : Le premier bit � afficher de l'intervalle
        - ms_bit          : Le dernier bit � afficher de l'intervalle

    RETOUR :
        - AUCUN
*/
void afficher_bits(unsigned int valeur_afficher, int ls_bit, int ms_bit);

#endif
