/****************************************************************************************
/*                                      DECODEUR_A429.H                                 *
/****************************************************************************************
    Auteur : Cristian Fermin Lopez
    Date   : 12 juin 2022

    Liste des fonctions publiques:

      - afficher_entete_decodeur : Affiche l'entête du programme en mode application
      - afficher_mot_a429        : Affiche un mot décodé selon le protocole ARINC A429 
      - decoder_mot_a429         : Décode un mot selont le protocole ARINC 429

*****************************************************************************************/
#ifndef __A429_DECODEUR__ 
#define __A429_DECODEUR__ 


/****************************************************************************************
*                           DÉFINTION DES TYPES ET CONSTANTES                           *
****************************************************************************************/



/****************************************************************************************
*                       DÉCLARATION DES FONCTIONS PUBLIQUES                             *
****************************************************************************************/

/*
    AFFICHER_ENTETE_DECODEUR

    Cette fonction affiche l'entête du programme principal
    lorsqu'il est exécuté en mode application.

    PARAMÈTRES :
        - AUCUN

    RETOUR :
        - AUCUN
*/
void afficher_entete_decodeur();

/*
    AFFICHER_MOT_A429

    Cette fonction d'afficher les données d'un mot décodé selon le
    protocole ARINC 429.

    PARAMÈTRES :
        - mot_ARINC429 : mot encodé sous le protole A429

    RETOUR :
        - AUCUN
*/
void afficher_mot_a429(unsigned int mot_ARINC429);

/*
    DECODER_MOT_A429

    Cette fonction permet de décodé un mot qui est encodé
    avec le protocole ARINC 429

    PARAMÈTRES :
        - mot_ARINC429    : mot encodé avec le protole A429
        - etat_corruption : permet de savoir l'état de corruption du mot donnée
                            (1 - mot corrompu, 0 - mot non corrompu)
        - num_mot         : le numéro du mot, permet de savoir qu'elle information est décodée
        - mot_BNR         : mot décodé de type BNR
        - donnee1_BCD     : 1er donnée décodé d'un mot de type BCD
        - donnee2_BCD     : 2eme donnée décodé d'un mot de type BCD
        - donnee3_BCD     : 3eme donnée décodé d'un mot de type BCD
        - donnee4_BCD     : 4eme donnée décodé d'un mot de type BCD

    RETOUR :
        - AUCUN
*/
void decoder_mot_a429(unsigned int mot_ARINC429, int* etat_corruption, int* num_mot, double* mot_BNR, int* donnee1_BCD, int* donnee2_BCD, int* donnee3_BCD, int* donnee4_BCD);

#endif
