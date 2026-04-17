#include "Parking.h"
#include "path.h"

#include <stdio.h>

int SaveClient(const Client tab_clients[], int compteurClient) {
    FILE *fichier = fopen(SuivieClientPath, "w");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return -1;
    }

    fprintf(fichier, "Plaque;Heure entrée;Heure sortie;Montant\n");

    for (int i = 0; i < compteurClient; i++) {
        fprintf(fichier, "%s;%s;%s;%.2f\n",
                tab_clients[i].plaque,
                tab_clients[i].heure_entree,
                tab_clients[i].heure_sortie,
                tab_clients[i].montant);
    }

    fclose(fichier);
    printf("Les clients ont été sauvegardés avec succès.\n");
    return 0;
}