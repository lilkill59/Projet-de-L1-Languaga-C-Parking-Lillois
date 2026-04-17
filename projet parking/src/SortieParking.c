#include "Parking.h"

#include <stdio.h>
#include <time.h>
#include <string.h>

int SortieParking(Parking tab_parking[], int compteur, time_t now) {
    if (compteur <= 0) {
        printf("Aucun parking disponible.\n");
        return -1;
    }

    char id[MAX_IDENTIFIANT], plaque[MAX_PLAQUE], heure_entree[6], heure_sortie[6];
    int i, heures, minutes, trouve_parking = 0, trouve_heure;
    float tarif = 2.5, total = 0;
    double duree;

    // Recherche du parking
    do {
        printf("Donner l'identifiant du parking : ");
        scanf("%19s", id);
        trouve_parking = 0;
        for (i = 0; i < compteur; i++) {
            if (strcmp(tab_parking[i].identifiant, id) == 0) {
                trouve_parking = 1;
                break;
            }
        }
        if (!trouve_parking) {
            printf("Parking %s non trouvé.\n", id);
        }
    } while (!trouve_parking);

    // Vérifications
    if (strcmp(tab_parking[i].etat, "FERME") == 0) {
        printf("Le parking %s est fermé.\n", tab_parking[i].nom);
        return -1;
    }
    if (tab_parking[i].places_disponibles <= 0) {
        printf("Le parking %s est déjà vide.\n", tab_parking[i].nom);
        return -1;
    }

    // Saisie de l'heure d'entrée
    do {
        trouve_heure = 0;
        printf("Heure d'entrée (HH:MM) : ");
        scanf("%5s", heure_entree);
        if (sscanf(heure_entree, "%d:%d", &heures, &minutes) != 2 || heures < 0 || heures > 23 || minutes < 0 || minutes > 59) {
            printf("Format invalide. Utilisez HH:MM.\n");
        } else {
            trouve_heure = 1;
        }
    } while (!trouve_heure);

    // Calcul de la durée
    struct tm tm_entree = {0};
    tm_entree.tm_hour = heures;
    tm_entree.tm_min = minutes;
    time_t now_local = time(NULL);
    struct tm *heure_locale = localtime(&now_local);
    tm_entree.tm_year = heure_locale->tm_year;
    tm_entree.tm_mon = heure_locale->tm_mon;
    tm_entree.tm_mday = heure_locale->tm_mday;
    time_t entree_time = mktime(&tm_entree);
    duree = difftime(now, entree_time) / 3600.0;

    if (duree < 0) {
        printf("L'heure d'entrée ne peut pas être dans le futur.\n");
        return -1;
    }

    // Calcul du montant
    strftime(heure_sortie, sizeof(heure_sortie), "%H:%M", localtime(&now));
    total = duree * tarif;
    printf("Plaque d'immatriculation : ");
    scanf("%19s", plaque);
    printf("Tarif : %.2f €/h, durée : %.2f h, total : %.2f €\n", tarif, duree, total);

    // Sauvegarde et mise à jour
    SuivieClient(plaque, heure_entree, heure_sortie, total);
    if (MAJ_Sortie(tab_parking, id, i, compteur) != 0) {
        return -1;
    }

    return 0;
}