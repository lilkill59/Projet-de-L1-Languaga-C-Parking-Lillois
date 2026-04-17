#include "Parking.h"

#include <stdio.h>
#include <string.h>

int SuprClient(Client tab_clients[], int *compteurClient) {
    if (*compteurClient <= 0) {
        printf("Aucun client à supprimer.\n");
        return *compteurClient;
    }

    char plaque[MAX_PLAQUE];
    printf("Entrez la plaque du client à supprimer : ");
    scanf("%19s", plaque);

    for (int i = 0; i < *compteurClient; i++) {
        if (strcmp(tab_clients[i].plaque, plaque) == 0) {
            // Suppression par décalage
            for (int j = i; j < *compteurClient - 1; j++) {
                tab_clients[j] = tab_clients[j + 1];
            }
            (*compteurClient)--;
            printf("Client supprimé avec succès.\n");
            return *compteurClient;
        }
    }

    printf("Client non trouvé.\n");
    return *compteurClient;
}