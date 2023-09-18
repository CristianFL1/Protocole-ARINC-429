/****************************************************************************************
/*                                      PORT_UDP                                        *
/****************************************************************************************
Auteur : Francis Bourdeau
Date   : 2 septembre 2015

Ce module permet la gestion d'un port UDP sous Windows.
Le code a �t� adapt� du site web de Glenn Fiedler, visit� le 02/09/2015
http://gafferongames.com/networking-for-game-programmers/sending-and-receiving-packets/


D�pendance avec des libraires additionnelles:
(project properties/linker/additionnal input/additionnal depencies
    - wsock32.lib


Liste des fonctions publiques:
    - initialiser_port_udp    : Permet de cr�er un port UDP.
    - detruire_port_udp       : Permet de lib�rer un port UDP.
    - recevoir_port_udp       : Permet de recevoire des donn�es sur un port UDP.
    - transmettre_port_udp    : Permet de transmettre des donn�es sur un port UDP.

*****************************************************************************************/

#ifndef __INF155_PORT_UDP__
#define __INF155_PORT_UDP__

/****************************************************************************************
*                           D�FINTION DES TYPES ET CONSTANTES                           *
****************************************************************************************/


/****************************************************************************************
*                       D�CLARATION DES FONCTIONS PUBLIQUES                             *
****************************************************************************************/

/*
    INITIALISER_PORT_UDP

    Cette fonction cr�e un port UDP et lui associe le num�ro re�u.
    
    Param�tres:
        - numero_port : Le num�ro attribu� au port UDP cr��.

    Retour: 
        - L'identifiant du port cr��.

    Example d'appel:
        int id_port_udp;
        id_port_udp = initialiser_port_udp(55001);
*/
int initialiser_port_udp(int numero_port);



/*
    DETRUIRE_PORT_UDP

    Cette fonction lib�re un port UDP une fois sa vie utile termin�e.
    Tout les ports cr�er � l'aide de initialiser_port_udp doivent lib�rer � l'aide
    de detruire_port_udp.
    
    Param�tres:
        - id_port_udp : L'identifiant du port UDP � d�truire..

    Retour: 
        - Aucun.

    Example d'appel:
        int id_port_udp;
        id_port_udp = initialiser_port_udp(55001);
            ... code ...
        detruire_port_udp(id_port_udp);

*/
void detruire_port_udp(int id_port_udp);



/*
    RECEVOIR_PORT_UDP

    Cette fonction tente de lire des donn�es sur un port UDP.
    L'op�ration de lecture est non-blocante.
    
    Param�tres:
        - id_port_udp : L'identifiant du port UDP � paritr du quel les donn�es sont lues.
        - donnees     : L'addresse o� les donn�es seront inscrite.
        - taille_donnees : L'espace disponible � l'addresse re�ues.

    Retour: 
        - Le nombre d'octets lus.

    Example d'appel:
        int id_port_udp;
        unsigned int valeur_recue;
        
        id_port_udp = initialiser_port_udp(55001);
        recevoir_port_udp(id_port_udp, &valeur_recue, sizeof(unsigned int));
*/
int recevoir_port_udp(int id_port_udp, void* donnees, int taille_donnees);



/*
    TRANSMETTRE_PORT_UDP

    Cette fonction tente d'�crire des donn�es sur un port UDP.
    L'op�ration d'�criture est non-blocante.
    
    Param�tres:
        - id_port_udp : L'identifiant du port UDP sur lequel les donn�es sont �crites.
        - donnees     : L'addresse o� les donn�es sont conserv�es.
        - taille_donnees : La quantit� de donn�es � transmettre (en octet).

    Retour: 
        - Le nombre d'octets lus.

    Example d'appel:
        int id_port_udp;
        unsigned int valeur_transmise = 0x7F;
        
        id_port_udp = initialiser_port_udp(55000);
        recevoir_port_udp(id_port_udp, 55001, &valeur_transmise, sizeof(unsigned int));
*/
int transmettre_port_udp(int id_port_udp_transmetteur, int numero_port_recepteur, 
                         void* donnees, int taille_donnees);


#endif