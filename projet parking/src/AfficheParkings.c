#include "Parking.h"
#include <stdio.h>

void AfficheParkings(const Parking tab_parking[], int compteur) {
    if (compteur <= 0) {
        printf("Aucun parking disponible.\n");
        return;
    }

    for (int i = 0; i < compteur; i++) {
        printf("Identifiant : %s\n", tab_parking[i].identifiant);
        printf("Nom : %s\n", tab_parking[i].nom);
        printf("Adresse : %s\n", tab_parking[i].adresse);
        printf("Ville : %s\n", tab_parking[i].ville);
        printf("Etat : %s\n", tab_parking[i].etat);
        printf("Places disponibles : %d\n", tab_parking[i].places_disponibles);
        printf("Capacité max : %d\n", tab_parking[i].capacite_max);
        printf("Date de mise à jour : %s\n", tab_parking[i].date_mise_a_jour);
        printf("Affichage panneaux : %s\n", tab_parking[i].affichage_panneaux);
        printf("\n");
    }
}