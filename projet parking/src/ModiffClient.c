#include "Parking.h"

#include <stdio.h>
#include <string.h>

int ModiffClient(Client tab_clients[], int *compteurClient) {
    if (*compteurClient <= 0) {
        printf("Aucun client à modifier.\n");
        return -1;
    }

    char plaque[MAX_PLAQUE];
    int i, trouve = 0;

    do {
        printf("Donner la plaque du client à modifier : ");
        scanf("%19s", plaque);
        for (i = 0; i < *compteurClient; i++) {
            if (strcmp(tab_clients[i].plaque, plaque) == 0) {
                trouve = 1;
                break;
            }
        }
        if (!trouve) {
            printf("Client %s non trouvé.\n", plaque);
        }
    } while (!trouve);

    printf("Modifier les informations du client %s :\n", tab_clients[i].plaque);

    do {
        printf("Nouvelle heure d'entrée (HH:MM) : ");
        scanf("%5s", tab_clients[i].heure_entree);
        int hh, mm;
        if (sscanf(tab_clients[i].heure_entree, "%d:%d", &hh, &mm) != 2 || hh < 0 || hh > 23 || mm < 0 || mm > 59) {
            printf("Format invalide. Utilisez HH:MM.\n");
        } else {
            break;
        }
    } while (1);

    do {
        printf("Nouvelle heure de sortie (HH:MM) : ");
        scanf("%5s", tab_clients[i].heure_sortie);
        int hh, mm;
        if (sscanf(tab_clients[i].heure_sortie, "%d:%d", &hh, &mm) != 2 || hh < 0 || hh > 23 || mm < 0 || mm > 59) {
            printf("Format invalide. Utilisez HH:MM.\n");
        } else {
            break;
        }
    } while (1);

    printf("Nouveau montant : ");
    scanf("%lf", &tab_clients[i].montant);

    printf("Client modifié avec succès.\n");
    return 0;
}