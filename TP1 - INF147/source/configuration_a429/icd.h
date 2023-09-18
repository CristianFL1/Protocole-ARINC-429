/****************************************************************************************
/*                                          ICD.H                                       *
/****************************************************************************************
    Auteur : Francis Bourdeau
    Date   : 2 septembre 2015

    Ce module contient le format utilisé pour transmettre des données vols en utilisant
    le protocole ARINC-429.

    Liste des fonctions publiques:
      - Aucunes.

*****************************************************************************************/

#ifndef __A429_ICD__
#define __A429_ICD__

/*
 *  Les types d'encodage disponible dans le protocole ARINC-429.
 */
#define     FORMAT_BNR          0
#define     FORMAT_BCD          1
#define     FORMAT_DISCRETS     2


/* 
 *  Signafication du champs SSM selon le format utilisé (Bit 30 et Bit 31)
 */
#define     SSM_PLUS_NORD_EST       0
#define     SSM_PAS_DE_DONNEE       1
#define     SSM_DONNEE_TEST         2
#define     SSM_MOINS_SUD_OUEST     3


/* 
 *  Format d'encodage du mot contenant l'heure (UTC)
 */
#define     NUMERO_MOT_UTC              150
#define     TYPE_MOT_UTC                BNR_LABEL
#define     RESOLUTION_MOT_UTC          1


/* 
 *  Format d'encodage du mot contenant l'aéroport de départ.
 */
#define     NUMERO_MOT_DEPART           232
#define     TYPE_MOT_DEPART             BCD_LABEL


/* 
 *  Format d'encodage du mot contenant l'altitude de l'appareil
 */
#define     NUMERO_MOT_ALTITUDE         252
#define     TYPE_MOT_ALTITUDE           BNR_LABEL
#define     RESOLUTION_MOT_ALTITUDE     1


/* 
 *  Format d'encodage du mot contenant l'aéroport de destination.
 */
#define     NUMERO_MOT_DESTINATION      255
#define     TYPE_MOT_DESTINATION        BCD_LABEL


/* 
 *  Format d'encodage du mot contenant la date.
 */
#define     NUMERO_MOT_DATE             260
#define     TYPE_MOT_DATE               BCD_LABEL


/* 
 *  Format d'encodage du mot contenant la latitude de l'appareil
 */
#define     NUMERO_MOT_LATITUDE         310
#define     TYPE_MOT_LATITUDE           BNR_LABEL
#define     RESOLUTION_MOT_LATITUDE     0.000172


/* 
 *  Format d'encodage du mot contenant la longitude de l'appareil
 */
#define     NUMERO_MOT_LONGITUDE        311
#define     TYPE_MOT_LONGITUDE          BNR
#define     RESOLUTION_MOT_LONGITUDE    0.000172


#endif