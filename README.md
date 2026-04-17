# Système de Gestion des Parkings de la Métropole Lilloise

Ce projet est un système de gestion des parkings développé en langage C pour la Métropole Lilloise. Il permet de gérer les entrées et sorties des véhicules, de suivre l'occupation des parkings, et de fournir un mode administrateur pour la gestion des données.

---

## Table des Matières

- [Fonctionnalités](#fonctionnalités)
- [Structure du Projet](#structure-du-projet)
- [Prérequis](#prérequis)
- [Installation](#installation)
- [Utilisation](#utilisation)
- [Fichiers CSV](#fichiers-csv)
- [Compilation](#compilation)
- [Auteurs](#auteurs)

---

## Fonctionnalités

- **Lecture des données des parkings** : Lecture des informations des parkings depuis un fichier CSV.
- **Affichage des parkings** : Affichage des informations d'un parking spécifique ou de tous les parkings.
- **Gestion des entrées et sorties** : Calcul du montant à payer en fonction du temps de stationnement.
- **Suivi des clients** : Enregistrement des informations des clients dans un fichier.
- **Gestion de l'occupation** : Mise à jour de la disponibilité des parkings.
- **Mode administrateur** : Accès sécurisé pour consulter et modifier les informations des parkings et des clients.
- **Vérification de la disponibilité** : Vérification si un parking est plein ou s'il y a des places disponibles.
- **Mise à jour des fichiers CSV** : Sauvegarde de l'état des parkings dans un fichier CSV.

---

## Structure du Projet
projet parking/

│

├── data/

│   ├── parking-metropole.csv

│   └── SuivieClient.csv

│

├── include/

│   ├── Parking.h

│   └── paths.h

│

├── src/

│   ├── Main.c

│   ├── LesParkings.c

│   ├── LesClients.c

│   ├── AfficheParking.c

│   ├── AfficheParkings.c

│   ├── AddParking.c

│   ├── ModiffParking.c

│   ├── SuprParking.c

│   ├── MAJ_Entree.c

│   ├── MAJ_Sortie.c

│   ├── SaveEtatPark.c

│   ├── SortieParking.c

│   ├── SuivieClient.c

│   ├── PlacesDispo.c

│   └── ModeAdmin.c

│

├── build/

│

└── README.md

---

## Prérequis

- Un compilateur C (comme `gcc`).
- Un système d'exploitation compatible (Windows, Linux, macOS).

---

## Installation

1. Clone ce dépôt sur ta machine locale :
   ```bash
   git clone https://github.com/lilkill59/Projet-de-L1-Languaga-C-Parking-Lillois.git projet parking
2.Accède au dossier du projet :
   ``bash
  cd "projet parking"

---
## Utilisation

Lancer le programme :

Compile le projet (voir section Compilation).
Exécute l'exécutable généré.


Menu principal :

Afficher un parking spécifique.
Afficher tous les parkings.
Accéder au mode administrateur.
Vérifier les places disponibles.
Quitter le programme.


Mode administrateur :

Modifier un parking.
Ajouter un parking.
Supprimer un parking.
Modifier un client.
Ajouter un client.
Supprimer un client.

---
## Fichiers CSV

parking-metropole.csv
Ce fichier contient les informations sur les parkings. Voici un exemple de format :

Identifiant;Nom;Adresse;Ville;Etat;Places disponibles;Capacité max;Date de mise à jour;Affichage panneaux
P001;Parking Central;123 Rue Principale;Paris;OUVERT;50;100;2023-10-01 12:00:00;50
P002;Parking Nord;456 Rue du Nord;Lyon;OUVERT;30;80;2023-10-01 12:00:00;30

SuivieClient.csv
Ce fichier contient les informations sur les clients. Voici un exemple de format :

Plaque;Heure entrée;Heure sortie;Montant
ABC123;08:30;10:45;5.25
XYZ789;09:15;12:30;8.75

##Compilation

Pour compiler le projet, place-toi dans le dossier racine du projet et exécute les commandes suivantes :

mkdir -p build
gcc -o build/parking src/*.c -I include



Pour exécuter le programme, utilise la commande suivante depuis le dossier racine :

./build/parking


---
## Auteurs

Lilian Beck : Développeur principal.

Remerciements

Université Polytechnique Hauts-de-France.
INSA Hauts-de-France.
--
