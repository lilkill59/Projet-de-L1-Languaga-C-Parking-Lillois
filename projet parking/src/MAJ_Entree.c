#include "Parking.h"

#include <stdio.h>
#include <time.h>
#include <string.h>

int MAJ_Entree(Parking tab_parking[], const char *id, int index, int compteur) {
    if (index < 0 || index >= compteur) {
        return -1;
    }

    tab_parking[index].places_disponibles++;
    if (strcmp(tab_parking[index].affichage_panneaux, "ABONNES") != 0) {
        char buffer[50];
        snprintf(buffer, sizeof(buffer), "%d", tab_parking[index].places_disponibles);
        STRNCPY(tab_parking[index].affichage_panneaux, buffer, MAX_AFFICHAGE_PANNEAUX);
    }

    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    strftime(tab_parking[index].date_mise_a_jour, MAX_DATE, "%Y-%m-%d %H:%M:%S", tm_info);

    SauvegardeEtatParking(tab_parking, compteur);
    return 0;
}