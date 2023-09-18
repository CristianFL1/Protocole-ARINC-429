/****************************************************************************************
/*                                      DECODEUR_A429.H                                 *
/****************************************************************************************
    Auteur : Cristian Fermin Lopez
    Date   : 12 juin 2022

    Liste des fonctions publiques:

      - afficher_entete_decodeur : Affiche l'ent�te du programme en mode application
      - afficher_mot_a429        : Affiche un mot d�cod� selon le protocole ARINC A429 
      - decoder_mot_a429         : D�code un mot selont le protocole ARINC 429

*****************************************************************************************/
#ifndef __A429_DECODEUR__ 
#define __A429_DECODEUR__ 


/****************************************************************************************
*                           D�FINTION DES TYPES ET CONSTANTES                           *
****************************************************************************************/



/****************************************************************************************
*                       D�CLARATION DES FONCTIONS PUBLIQUES                             *
****************************************************************************************/

/*
    AFFICHER_ENTETE_DECODEUR

    Cette fonction affiche l'ent�te du programme principal
    lorsqu'il est ex�cut� en mode application.

    PARAM�TRES :
        - AUCUN

    RETOUR :
        - AUCUN
*/
void afficher_entete_decodeur();

/*
    AFFICHER_MOT_A429

    Cette fonction d'afficher les donn�es d'un mot d�cod� selon le
    protocole ARINC 429.

    PARAM�TRES :
        - mot_ARINC429 : mot encod� sous le protole A429

    RETOUR :
        - AUCUN
*/
void afficher_mot_a429(unsigned int mot_ARINC429);

/*
    DECODER_MOT_A429

    Cette fonction permet de d�cod� un mot qui est encod�
    avec le protocole ARINC 429

    PARAM�TRES :
        - mot_ARINC429    : mot encod� avec le protole A429
        - etat_corruption : permet de savoir l'�tat de corruption du mot donn�e
                            (1 - mot corrompu, 0 - mot non corrompu)
        - num_mot         : le num�ro du mot, permet de savoir qu'elle information est d�cod�e
        - mot_BNR         : mot d�cod� de type BNR
        - donnee1_BCD     : 1er donn�e d�cod� d'un mot de type BCD
        - donnee2_BCD     : 2eme donn�e d�cod� d'un mot de type BCD
        - donnee3_BCD     : 3eme donn�e d�cod� d'un mot de type BCD
        - donnee4_BCD     : 4eme donn�e d�cod� d'un mot de type BCD

    RETOUR :
        - AUCUN
*/
void decoder_mot_a429(unsigned int mot_ARINC429, int* etat_corruption, int* num_mot, double* mot_BNR, int* donnee1_BCD, int* donnee2_BCD, int* donnee3_BCD, int* donnee4_BCD);

#endif
