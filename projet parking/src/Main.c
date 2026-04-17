#include "Parking.h"
#include "path.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    Parking tab_parking[MAX_PARKINGS];
    int compteur = 0;

    if (LesParkings(tab_parking, &compteur) != 0) {
        printf("Erreur lors du chargement des parkings.\n");
        printf("Appuyez sur Entrée pour quitter...");
        getchar();
        return 1;
    }
    printf("Données des parkings chargées avec succès.\n");

    int choix;
    do {
        printf("\n1. Afficher un parking\n");
        printf("2. Afficher tous les parkings\n");
        printf("3. Mode administrateur\n");
        printf("4. Vérifier les places disponibles\n");
        printf("5. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);
        getchar(); // Pour consommer le '\n' restant

        switch (choix) {
            case 1:
                AfficheParking(tab_parking, compteur);
                break;
            case 2:
                AfficheParkings(tab_parking, compteur);
                break;
            case 3:
                ModeAdministrateur(tab_parking, &compteur);
                break;
            case 4:
                verifierPlacesDisponibles(tab_parking, compteur);
                break;
            case 5:
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 5);

    printf("Appuyez sur Entrée pour quitter...");
    getchar();
    return 0;
}