/****************************************************************************************
/*                                      PORT_UDP                                        *
/****************************************************************************************
Auteur : Francis Bourdeau
Date   : 2 septembre 2015

Ce module permet la gestion d'un port UDP sous Windows.
Le code a été adapté du site web de Glenn Fiedler, visité le 02/09/2015
http://gafferongames.com/networking-for-game-programmers/sending-and-receiving-packets/

*****************************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <winsock2.h>

#include "port_udp.h"
#include "configuration.h"



/****************************************************************************************
*                           DÉFINTION DES TYPES ET CONSTANTES                           *
****************************************************************************************/

/*
 *  Définition de l'address IP 127.0.0.1 sur un entier de 32 bits.
 */
#define LOCAL_HOST  (( 127 << 24 ) | ( 0 << 16 ) |  ( 0 << 8  ) | (1 << 0))


/*
 *  Création d'une macro permettant d'afficher les traces de débuggages seulement 
 *  lorsque le bon mode est activé.
 */
#if defined(MODE_DEBUG) || defined(MODE_TEST)
#define UDP_LOG(format, ...)   printf(format, __VA_ARGS__)
#else
#define UDP_LOG(format, ...)
#endif



/****************************************************************************************
*                           DÉFINTION DES FONCTIONS PUBLIQUES                           *
****************************************************************************************/


int initialiser_port_udp(int numero_port)
{
    int erreur;                         /* Code d'erreur reçue lors de l'initialisation 
                                           du port.                 */
    int id_socket;                      /* Identifiant du port udp. */
    struct sockaddr_in addresse_ip;     /* L'addresse IP du port    */

    WSADATA WsaData;                            /* Données internes de l'API Windows.*/
    unsigned long operation_non_blocante;       /* Mode d'opération du port.         */

    /* Initialisation de la couche IP. */
    WSAStartup(MAKEWORD(2,2), &WsaData);

    /* Création du port UDP. */
    id_socket = socket( AF_INET, SOCK_DGRAM, IPPROTO_UDP );
    if(id_socket <= EXIT_SUCCESS)
    {
        UDP_LOG("ERREUR : échec lors de la création du port [%i]\n", numero_port);
        exit(EXIT_FAILURE);
    }

    /* Association du port UDP à son numéro de port */
    addresse_ip.sin_family = AF_INET;
    addresse_ip.sin_addr.s_addr = INADDR_ANY;
    addresse_ip.sin_port = htons(numero_port);
    erreur = bind(id_socket, 
                 (const struct sockaddr*) &addresse_ip, 
                  sizeof(struct sockaddr_in));
    if(erreur < EXIT_SUCCESS)
    {
        UDP_LOG("ERREUR : échec lors de l\'assocation du port  [%i]\n", numero_port);
        exit(EXIT_FAILURE);
    }

    /* Placer le port UDP en opération non-blocante. */
    operation_non_blocante = 1;
    if (ioctlsocket(id_socket, FIONBIO, &operation_non_blocante) != EXIT_SUCCESS)
    {
        UDP_LOG("ERREUR: le port [%i] ne peut être placer en mode non-blocant\n", numero_port);
        exit(EXIT_FAILURE);
    }

    return id_socket;
}



void detruire_port_udp(int id_port_udp)
{
    /* Fermeture du port et de la couche IP. */
    closesocket(id_port_udp);
    WSACleanup();
}



int recevoir_port_udp(int id_port_udp, void* donnees, int taille_donnees)
{
    int                 nb_octets_recus;    /* Le nombre d'octets disponibles sur le 
                                               port UDP.*/
    struct sockaddr_in  sender_address;     /* Addresse IP du transmetteur. */
    int                 sender_size;        /* Taille de l'addresse IP*/

    /* Initialisation des données */
    sender_size = sizeof(sender_address);

    /* On tente de lire sur le port UDP */
    nb_octets_recus = recvfrom(id_port_udp, (char*) donnees, taille_donnees,
                               0, (struct sockaddr*) &sender_address, &sender_size);

    return nb_octets_recus;
}

int transmettre_port_udp(int id_port_udp_transmetteur, int numero_port_recepteur, 
                         void* donnees, int taille_donnees)
{
    int nb_octets_transmis;             /* Le nombre d'octets transmis sur le port UDP. */
    struct sockaddr_in addresse_ip;     /* L'addresse IP du port UDP sur lequel on lit. */
    int taille_addresse;                /* La traille de l'adresse IP.                  */


    /* Les lectures se font seulement sur un port local. */
    addresse_ip.sin_family = AF_INET;
    addresse_ip.sin_addr.s_addr = htonl(LOCAL_HOST);
    addresse_ip.sin_port = htons( numero_port_recepteur );
    taille_addresse = sizeof(addresse_ip);


    nb_octets_transmis = sendto(id_port_udp_transmetteur, (char *) donnees, taille_donnees, 
                                0, (struct sockaddr*) &addresse_ip, taille_addresse);

    return nb_octets_transmis;
}
