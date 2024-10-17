#include <iostream>
#include <vector>
#include "ressource.h"

using namespace std;

Ressource::Ressource(){}

Ressource::Ressource(int id_Ressource,string nomRessource,string dateAquisition)
{
    this->id_Ressource=id_Ressource;
    this->nomRessource=nomRessource;
    this->dateAquisition=dateAquisition;
}

Ressource::~Ressource()
{
}

 Ressource::Ressource(const Ressource& r )
 {
     this->id_Ressource=r.id_Ressource;
     this->nomRessource=r.nomRessource;
     this->dateAquisition=r.dateAquisition;
 }

istream& operator>> (istream& in, Ressource& r)
{
    cout << "Saisie des informations de la Ressource : " << endl;
    cout << "ID de la Ressource : ";
    in >> r.id_Ressource;
    in.ignore();
    cout << "Nom de la Ressource : ";
    getline(in, r.nomRessource);
    cout << "Date d'acquisition : ";
    getline(in, r.dateAquisition);
    return in;
}


void Ressource::afficherRessource() {
    cout << "ID de la Ressource : " << id_Ressource << endl;
    cout << "Nom de la Ressource : " << nomRessource << endl;
    cout << "Date d'acquisition : " << dateAquisition << endl;
}

void Ressource::AfficherDescription() {
    if (description != nullptr) {
        cout << "Description de la ressource : " << *description << endl;
    } else {
        cout << "Aucune description disponible pour cette ressource." << endl;
    }
}

Ressource& Ressource::operator=(const Ressource& autre) {
    if (this != &autre) {
        id_Ressource = autre.id_Ressource;
        nomRessource = autre.nomRessource;
        dateAquisition = autre.dateAquisition;


                description = new string(*autre.description);

                *description = *autre.description;

            delete description;
            description = nullptr;
        }

    return *this;
}

