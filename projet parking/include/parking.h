#ifndef PARKING_H
#define PARKING_H

#include <stdio.h>
#include <time.h>

// Constantes pour les tailles maximales des champs
#define MAX_IDENTIFIANT 20
#define MAX_NOM 100
#define MAX_ADRESSE 255
#define MAX_VILLE 100
#define MAX_ETAT 50
#define MAX_AFFICHAGE_PANNEAUX 50
#define MAX_DATE 20
#define MAX_PLAQUE 20
#define MAX_PARKINGS 1000
#define MAX_CLIENTS 1000

// Macro pour une copie sécurisée de chaînes
#define STRNCPY(dest, src, size) do { \
    strncpy(dest, src, size - 1); \
    dest[size - 1] = '\0'; \
} while (0)

// Structure pour représenter un parking
typedef struct {
    char identifiant[MAX_IDENTIFIANT];
    char nom[MAX_NOM];
    char adresse[MAX_ADRESSE];
    char ville[MAX_VILLE];
    char etat[MAX_ETAT];
    int places_disponibles;
    int capacite_max;
    char date_mise_a_jour[MAX_DATE];
    char affichage_panneaux[MAX_AFFICHAGE_PANNEAUX];
} Parking;

// Structure pour représenter un client
typedef struct {
    char plaque[MAX_PLAQUE];
    char heure_entree[6];
    char heure_sortie[6];
    double montant;
} Client;

// ======================
// Section : Affichage
// ======================
void AfficheParking(const Parking tab_parking[], int compteur);
void AfficheParkings(const Parking tab_parking[], int compteur);

// ======================
// Section : Gestion des Parkings
// ======================
int LesParkings(Parking tab_parking[], int *compteur);
int AddParking(Parking tab_parking[], int compteur);
int ModiffParking(Parking tab_parking[], int *compteur);
int SuprParking(Parking tab_parking[], int *compteur);
int MAJ_Entree(Parking tab_parking[], const char *id, int index, int compteur);
int MAJ_Sortie(Parking tab_parking[], const char *id, int index, int compteur);
int SauvegardeEtatParking(const Parking tab_parking[], int compteur);

// ======================
// Section : Gestion des Clients
// ======================
int LesClients(Client tab_clients[], int *compteurClient);
int AddClient(Client tab_clients[], int compteurClient);
int ModiffClient(Client tab_clients[], int *compteurClient);
int SuprClient(Client tab_clients[], int *compteurClient);
int SaveClient(const Client tab_clients[], int compteurClient);

// ======================
// Section : Fonctions Utilitaires
// ======================
int verifierPlacesDisponibles(const Parking tab_parking[], int compteur);
int SortieParking(Parking tab_parking[], int compteur, time_t now);
void SuivieClient(const char *plaque, const char *heure_entree, const char *heure_sortie, double montant);

// ======================
// Section : Mode Administrateur
// ======================
int ModeAdministrateur(Parking tab_parking[], int *compteur);

#endif // PARKING_H