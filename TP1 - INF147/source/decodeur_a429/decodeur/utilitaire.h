/****************************************************************************************
/*                                      UTILITAIRE.H                                    *
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
#ifndef __A429_UTILITAIRE__ 
#define __A429_UTILITAIRE__



/****************************************************************************************
*                           DÉFINTION DES TYPES ET CONSTANTES                           *
****************************************************************************************/


/****************************************************************************************
*                       DÉCLARATION DES FONCTIONS PUBLIQUES                             *
****************************************************************************************/

/*
    AFFICHER_HEURE

    Cette fonction permet d'afficher l'heure en fonction du nombre
    de seconde donné avec le format suivant : 00h00m00s

    PARAMÈTRES :
        - seconde : Le nombre de seconde à convertir selon format

    RETOUR :
        - AUCUN
*/
void afficher_heure(unsigned int seconde);

/*
    DECIMALE_A_OCTALE

    Cette fonction convertie un nombre interprété à base décimale
    en un nombre interprété à base octale.

    PARAMÈTRES :
        - decimal : Le nombre interprété en base 10

    RETOUR :
        - Le nombre interprété en base 8
*/
unsigned int decimale_a_octale(unsigned int decimal);

/*
    CALCULER_NB_BITS_ACTIFS

    Cette fonction permet de calculer le nombre de bit actif
    dans une valeur donnée. La fonctione est principalement utilisée
    pour savoir si la valeur donnée est de parité pair ou impair

    PARAMÈTRES :
        - valeur : La valeur pour laquelle on veut calculer le nombre de bit actif

    RETOUR :
        - Le nombre de bit actif
*/
unsigned int calculer_nb_bits_actifs(unsigned int valeur);

/*
    AFFICHER_BITS

    
    Cette fonction permet d'afficher une valeur donné en base 2.
    L'intervalle des bits à afficher doit être précisé avec les deux
    paramètres (ls_bit et ms_bit).

    PARAMÈTRES :
        - valeur_afficher : La valeur pour laquelle on veut afficher les bits
        - ls_bit          : Le premier bit à afficher de l'intervalle
        - ms_bit          : Le dernier bit à afficher de l'intervalle

    RETOUR :
        - AUCUN
*/
void afficher_bits(unsigned int valeur_afficher, int ls_bit, int ms_bit);

#endif
