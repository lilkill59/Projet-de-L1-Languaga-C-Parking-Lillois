#include "Parking.h"

#include <stdio.h>
#include <time.h>
#include <string.h>

int ModiffParking(Parking tab_parking[], int *compteur) {
    if (*compteur <= 0) {
        printf("Aucun parking à modifier.\n");
        return -1;
    }

    char id[MAX_IDENTIFIANT];
    int i, trouve = 0;

    do {
        printf("Donner l'identifiant du parking à modifier : ");
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

    printf("Modifier les informations du parking %s :\n", tab_parking[i].nom);
    printf("Nouveau nom : ");
    scanf("%99s", tab_parking[i].nom);
    getchar(); // Pour consommer le '\n' restant
    printf("Nouvelle adresse : ");
    fgets(tab_parking[i].adresse, MAX_ADRESSE, stdin);
    tab_parking[i].adresse[strcspn(tab_parking[i].adresse, "\n")] = '\0';
    printf("Nouvelle ville : ");
    scanf("%99s", tab_parking[i].ville);
    printf("Nouvel état : ");
    scanf("%49s", tab_parking[i].etat);
    printf("Nouveau nombre de places disponibles : ");
    scanf("%d", &tab_parking[i].places_disponibles);
    printf("Nouvelle capacité max : ");
    scanf("%d", &tab_parking[i].capacite_max);

    // Mise à jour de la date
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    strftime(tab_parking[i].date_mise_a_jour, MAX_DATE, "%Y-%m-%d %H:%M:%S", tm_info);

    printf("Nouvel affichage panneaux : ");
    scanf("%49s", tab_parking[i].affichage_panneaux);

    printf("Parking modifié avec succès.\n");
    return 0;
}