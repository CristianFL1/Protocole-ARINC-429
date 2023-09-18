/****************************************************************************************
/                               MODULE Décodeur ARINC-A429                              *
/****************************************************************************************
   Auteur : Cristian Fermin Lopez
   Date   : 12 juin 2022

   Ce programme permet de décoder et afficher des mots endcodé sous le protocole
   ARINC 429
****************************************************************************************/

#include <stdio.h>
#include <stdbool.h>

#include "configuration.h"


/****************************************************************************************
*                           DÉFINTION DES FONCTIONS PUBLIQUES                           *
****************************************************************************************/
#if(APPLICATION)
int main(void)
{
	// Affichage de l'entête du programme : mode APPLICATION
	afficher_entete_decodeur();

	int id_port = initialiser_port_udp(port_udp);
	
	unsigned int valeur_recue = NULL;
	unsigned int ancienne_valeur = 0;
	int nb_octet;

	// Boucle inifini pour recevoir les données 
	while(true)
	{
		nb_octet = recevoir_port_udp(id_port, &valeur_recue, sizeof(unsigned int)); 
		
		// Si la donnée est la même que la denière, on ne la re affiche pas
		if (ancienne_valeur != valeur_recue)
			afficher_mot_a429(valeur_recue);

		ancienne_valeur = valeur_recue;
	}
	
	return 0;
}
#endif

