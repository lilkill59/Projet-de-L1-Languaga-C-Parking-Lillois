#include "Parking.h"

#include <stdio.h>

int AddClient(Client tab_clients[], int compteurClient) {
    if (compteurClient >= MAX_CLIENTS) {
        printf("Nombre maximum de clients atteint.\n");
        return compteurClient;
    }

    printf("Entrez la plaque d'immatriculation du client : ");
    scanf("%19s", tab_clients[compteurClient].plaque);

    do {
        printf("Entrez l'heure d'entrée (HH:MM) : ");
        scanf("%5s", tab_clients[compteurClient].heure_entree);
        int hh, mm;
        if (sscanf(tab_clients[compteurClient].heure_entree, "%d:%d", &hh, &mm) != 2 || hh < 0 || hh > 23 || mm < 0 || mm > 59) {
            printf("Format invalide. Utilisez HH:MM.\n");
        } else {
            break;
        }
    } while (1);

    do {
        printf("Entrez l'heure de sortie (HH:MM) : ");
        scanf("%5s", tab_clients[compteurClient].heure_sortie);
        int hh, mm;
        if (sscanf(tab_clients[compteurClient].heure_sortie, "%d:%d", &hh, &mm) != 2 || hh < 0 || hh > 23 || mm < 0 || mm > 59) {
            printf("Format invalide. Utilisez HH:MM.\n");
        } else {
            break;
        }
    } while (1);

    printf("Entrez le montant à payer : ");
    scanf("%lf", &tab_clients[compteurClient].montant);

    printf("Client ajouté avec succès.\n");
    return compteurClient + 1;
}