#include "Parking.h"
#include "path.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int LesParkings(Parking tab_parking[], int *compteur) {
    FILE *fichier = fopen(ParkingPath, "r");
    if (fichier == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier '%s'. Vérifiez que le fichier existe et que le chemin est correct.\n", ParkingPath);
        return -1;
    }

    char ligne[512];
    if (fgets(ligne, sizeof(ligne), fichier) == NULL) { // Ignorer l'en-tête
        fclose(fichier);
        return -1;
    }

    while (fgets(ligne, sizeof(ligne), fichier) != NULL && *compteur < MAX_PARKINGS) {
        Parking parking;
        char *token = strtok(ligne, ";");
        if (token == NULL) continue;
        STRNCPY(parking.identifiant, token, MAX_IDENTIFIANT);

        token = strtok(NULL, ";");
        if (token == NULL) continue;
        STRNCPY(parking.nom, token, MAX_NOM);

        token = strtok(NULL, ";");
        if (token == NULL) continue;
        STRNCPY(parking.adresse, token, MAX_ADRESSE);

        token = strtok(NULL, ";");
        if (token == NULL) continue;
        STRNCPY(parking.ville, token, MAX_VILLE);

        token = strtok(NULL, ";");
        if (token == NULL) continue;
        STRNCPY(parking.etat, token, MAX_ETAT);

        token = strtok(NULL, ";");
        if (token == NULL) continue;
        parking.places_disponibles = atoi(token);

        token = strtok(NULL, ";");
        if (token == NULL) continue;
        parking.capacite_max = atoi(token);

        token = strtok(NULL, ";");
        if (token == NULL) continue;
        STRNCPY(parking.date_mise_a_jour, token, MAX_DATE);

        token = strtok(NULL, ";");
        if (token == NULL) continue;
        STRNCPY(parking.affichage_panneaux, token, MAX_AFFICHAGE_PANNEAUX);

        tab_parking[*compteur] = parking;
        (*compteur)++;
    }

    fclose(fichier);
    printf("Nombre de parkings lus : %d\n", *compteur);
    return 0;
}