#include "Parking.h"
#include "path.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int LesClients(Client tab_clients[], int *compteurClient) {
    FILE *fichier = fopen(SuivieClientPath, "r");
    if (fichier == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier '%s'. Vérifiez que le fichier existe et que le chemin est correct.\n", SuivieClientPath);
        return -1;
    }

    char ligne[512];
    if (fgets(ligne, sizeof(ligne), fichier) == NULL) { // Ignorer l'en-tête
        fclose(fichier);
        return 0;
    }

    while (fgets(ligne, sizeof(ligne), fichier) != NULL && *compteurClient < MAX_CLIENTS) {
        Client client;
        char *token = strtok(ligne, ";");
        if (token == NULL) continue;
        STRNCPY(client.plaque, token, MAX_PLAQUE);

        token = strtok(NULL, ";");
        if (token == NULL) continue;
        STRNCPY(client.heure_entree, token, 6);

        token = strtok(NULL, ";");
        if (token == NULL) continue;
        STRNCPY(client.heure_sortie, token, 6);

        token = strtok(NULL, ";");
        if (token == NULL) continue;
        client.montant = atof(token);

        tab_clients[*compteurClient] = client;
        (*compteurClient)++;
    }

    fclose(fichier);
    printf("Nombre de clients lus : %d\n", *compteurClient);
    return 0;
}