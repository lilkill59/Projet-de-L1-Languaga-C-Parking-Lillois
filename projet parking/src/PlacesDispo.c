#include "Parking.h"

#include <stdio.h>
#include <string.h>

int verifierPlacesDisponibles(const Parking tab_parking[], int compteur) {
    if (compteur <= 0) {
        printf("Aucun parking disponible.\n");
        return -1;
    }

    char id[MAX_IDENTIFIANT];
    printf("Entrez l'identifiant du parking à vérifier : ");
    scanf("%19s", id);

    for (int i = 0; i < compteur; i++) {
        if (strcmp(tab_parking[i].identifiant, id) == 0) {
            if (tab_parking[i].places_disponibles == 0) {
                printf("Le parking %s est plein.\n", id);
                return 1;
            } else {
                printf("Le parking %s a %d places disponibles.\n", id, tab_parking[i].places_disponibles);
                return 0;
            }
        }
    }

    printf("Parking %s non trouvé.\n", id);
    return -1;
}