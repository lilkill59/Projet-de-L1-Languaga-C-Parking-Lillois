#include "Parking.h"
#include <stdio.h>
#include <string.h>

int SuprParking(Parking tab_parking[], int *compteur) {
    if (*compteur <= 0) {
        printf("Aucun parking à supprimer.\n");
        return *compteur;
    }

    char id[MAX_IDENTIFIANT];
    int i, trouve = 0;

    do {
        printf("Donner l'identifiant du parking à supprimer : ");
        scanf("%19s", id);
        for (i = 0; i < *compteur; i++) {
            if (strcmp(tab_parking[i].identifiant, id) == 0) {
                trouve = 1;
                break;
            }
        }
        if (!trouve) {
            printf("Parking %s non trouvé.\n", id);
        }
    } while (!trouve);

    // Suppression par décalage
    for (int j = i; j < *compteur - 1; j++) {
        tab_parking[j] = tab_parking[j + 1];
    }

    (*compteur)--;
    printf("Parking %s supprimé avec succès.\n", id);
    return *compteur;
}