#include "Parking.h"
#include "path.h"

#include <stdio.h>

int SauvegardeEtatParking(const Parking tab_parking[], int compteur) {
    FILE *fichier = fopen(ParkingPath, "w");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return -1;
    }

    // Écriture de l'en-tête
    fprintf(fichier, "Identifiant;Nom;Adresse;Ville;Etat;Places disponibles;Capacité max;Date de mise à jour;Affichage panneaux\n");

    // Écriture des données des parkings
    for (int i = 0; i < compteur; i++) {
        fprintf(fichier, "%s;%s;%s;%s;%s;%d;%d;%s;%s\n",
                tab_parking[i].identifiant,
                tab_parking[i].nom,
                tab_parking[i].adresse,
                tab_parking[i].ville,
                tab_parking[i].etat,
                tab_parking[i].places_disponibles,
                tab_parking[i].capacite_max,
                tab_parking[i].date_mise_a_jour,
                tab_parking[i].affichage_panneaux);
    }

    fclose(fichier);
    printf("L'état des parkings a été sauvegardé avec succès dans %s.\n", ParkingPath);
    return 0;
}