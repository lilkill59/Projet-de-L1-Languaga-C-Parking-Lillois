#include "Parking.h"

#include <stdio.h>
#include <time.h>
#include <string.h>

int AddParking(Parking tab_parking[], int compteur) {
    if (compteur >= MAX_PARKINGS) {
        printf("Nombre maximum de parkings atteint.\n");
        return compteur;
    }

    Parking new_parking;

    printf("Ajouter un nouveau parking :\n");
    printf("Identifiant : ");
    scanf("%19s", new_parking.identifiant);
    printf("Nom : ");
    scanf("%99s", new_parking.nom);
    getchar(); // Pour consommer le '\n' restant
    printf("Adresse : ");
    fgets(new_parking.adresse, MAX_ADRESSE, stdin);
    new_parking.adresse[strcspn(new_parking.adresse, "\n")] = '\0'; // Supprimer le '\n'
    printf("Ville : ");
    scanf("%99s", new_parking.ville);
    printf("État : ");
    scanf("%49s", new_parking.etat);
    printf("Places disponibles : ");
    scanf("%d", &new_parking.places_disponibles);
    printf("Capacité max : ");
    scanf("%d", &new_parking.capacite_max);

    // Mise à jour de la date
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    strftime(new_parking.date_mise_a_jour, MAX_DATE, "%Y-%m-%d %H:%M:%S", tm_info);

    printf("Affichage panneaux : ");
    scanf("%49s", new_parking.affichage_panneaux);

    tab_parking[compteur] = new_parking;
    printf("Nouveau parking ajouté avec succès.\n");
    return compteur + 1;
}