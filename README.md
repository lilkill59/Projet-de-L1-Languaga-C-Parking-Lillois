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
