#include "Parking.h"
#include <stdio.h>

void SuivieClient(const char *plaque, const char *heure_entree, const char *heure_sortie, double montant) {
    FILE *fichier = fopen("SuivieClient.csv", "a");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    // Écriture de l'en-tête si le fichier est vide
    fseek(fichier, 0, SEEK_END);
    if (ftell(fichier) == 0) {
        fprintf(fichier, "Plaque;Heure entrée;Heure sortie;Montant\n");
    }

    fprintf(fichier, "%s;%s;%s;%.2f\n", plaque, heure_entree, heure_sortie, montant);
    fclose(fichier);
}