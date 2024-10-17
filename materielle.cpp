#include <iostream>
#include <vector>
#include "ressource.h"
#include "materielle.h"

using namespace std;

Materielle::Materielle(){}

Materielle::Materielle(int id, string nom, string date, int quantite)
    : Ressource(id, nom, date), quantiteDisponible(quantite) {}

Materielle::~Materielle() {
    delete[] materielsDisponibles;
}

void Materielle::afficherRessource() {
    Ressource::afficherRessource();
    cout << "Quantite disponible : " << quantiteDisponible << endl;
}

istream& operator>> (istream& in,Materielle& m)
{
    Ressource *r=&m;
    in>>*r;
    cout << "Quantite disponible : ";
    cin >> m.quantiteDisponible;
    cout << "Nombre de materiaux disponibles : ";
    int nbMateriels;
    cin >> nbMateriels;
    m.materielsDisponibles = new string[nbMateriels];
    cout << "Saisir les materiaux disponibles :" << endl;
    for (int i = 0; i < nbMateriels; ++i) {
        cout << "Materiel " << i + 1 << " : ";
        cin >> m.materielsDisponibles[i];
    }
    return in;
}

void Materielle::afficherMaterielsDisponibles() {
    cout << "Materiaux disponibles :" << endl;
    for (int i = 0; i < quantiteDisponible; ++i) {
        cout << "- " << materielsDisponibles[i] << endl;
    }
}

 Materielle::Materielle(const Materielle& m)
    : Ressource(m), quantiteDisponible(m.quantiteDisponible)
{
    materielsDisponibles = new string[m.quantiteDisponible];
    for (int i = 0; i < m.quantiteDisponible; i++)
    {
        materielsDisponibles[i] = m.materielsDisponibles[i];
    }
}

Materielle& Materielle::operator=(const Materielle& m)
{
    if (this!=&m)
    {
        Ressource::operator=(m);
        quantiteDisponible=m.quantiteDisponible;
        materielsDisponibles = new string[quantiteDisponible];
        for (int i=0;i<quantiteDisponible;i++)
        {
            materielsDisponibles[i] = m.materielsDisponibles[i];
        }
    }
    return *this;
}



















