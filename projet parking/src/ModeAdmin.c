#include "Parking.h"
#include "path.h"
#include <stdio.h>
#include <string.h>

int ModeAdministrateur(Parking tab_parking[], int *compteur) {
    char mdp[50];
    printf("Mot de passe : ");
    scanf("%49s", mdp);
    if (strcmp(mdp, "admin123") != 0) {
        printf("Mot de passe incorrect.\n");
        return -1;
    }

    Client tab_clients[MAX_CLIENTS];
    int compteurClient = 0;
    LesClients(tab_clients, &compteurClient);

    int choix;
    do {
        printf("\n1. Modifier un parking\n2. Ajouter un parking\n3. Supprimer un parking\n");
        printf("4. Modifier un client\n5. Ajouter un client\n6. Supprimer un client\n7. Quitter\nChoix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ModiffParking(tab_parking, compteur);
                SauvegardeEtatParking(tab_parking, *compteur);
                break;
            case 2:
                *compteur = AddParking(tab_parking, *compteur);
                SauvegardeEtatParking(tab_parking, *compteur);
                break;
            case 3:
                *compteur = SuprParking(tab_parking, compteur);
                SauvegardeEtatParking(tab_parking, *compteur);
                break;
            case 4:
                ModiffClient(tab_clients, &compteurClient);
                SaveClient(tab_clients, compteurClient);
                break;
            case 5:
                compteurClient = AddClient(tab_clients, compteurClient);
                SaveClient(tab_clients, compteurClient);
                break;
            case 6:
                compteurClient = SuprClient(tab_clients, &compteurClient);
                SaveClient(tab_clients, compteurClient);
                break;
            case 7:
                return 0;
            default:
                printf("Choix invalide.\n");
        }
    } while (1);
}