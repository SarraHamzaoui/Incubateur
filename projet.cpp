#include "projet.h"
#include <iostream>
#include <string>

using namespace std;

Projet::Projet(){}
Projet::Projet(int id_projet ,string nom_projet,string objectif,double prix ,int etape_dev)
{
    this->id_projet=id_projet;
    this->nom_projet=nom_projet;
    this->objectif=objectif;
    this->prix=prix;
    this->etape_dev=etape_dev;
}
Projet::~Projet(){}

///surcharge de >>

istream& operator>> (istream& in, Projet& p)
{
    try {
        cout << "Donner l'ID du projet (positif) : ";
        if (!(in >> p.id_projet) || p.id_projet <= 0) {
            throw ("L'ID du projet doit etre un entier positif.");
        }

        cout << "Donner le nom du projet : ";
        if (!(in >> p.nom_projet)) {
            throw ("Erreur de saisie pour le nom du projet.");
        }

        cout << "Donner l'objectif du projet : ";
        in.ignore();
        getline(in, p.objectif);
        if (in.fail()) {
            throw ("Erreur lors de la saisie de l'objectif du projet.");
        }

        cout << "Donner le prix du projet (positif) : ";
        if (!(in >> p.prix) || p.prix <= 0) {
            throw ("Le prix du projet doit être un nombre positif.");
        }

        cout << "Donner l'étape de developpement (positif) : ";
        if (!(in >> p.etape_dev) || p.etape_dev <= 0) {
            throw ("L'etape de developpement du projet doit etre un entier positif.");
        }

        cout << "Saisie avec succes." << endl;
    } catch (const exception& e) {
        cerr << "Erreur : " << e.what() << endl;
        throw;
    }

    return in;
}

ostream& operator<< (ostream& out,Projet& p)
{
    out << "ID du projet: " << p.id_projet << endl;
    out << "Nom du projet : " << p.nom_projet << endl;
    out << "Objectif : " << p.objectif << endl;
    out << "Prix : " << p.prix << endl;
    out << "Etape de developpement : " << p.etape_dev << endl;
    return out;
}

int Projet::getIdProjet()
{
    return this->id_projet;
}

string Projet::getNomProjet()
{
    return this->nom_projet;
}

double Projet::getPrix()
{
    return this->prix;
}



