#include <iostream>
#include <vector>

#include "ressource.h"
#include "humaine.h"

using namespace std;

Humaine::Humaine(){}

Humaine::Humaine(int id, string nom, string date, string expertise, int nbPers)
    : Ressource(id, nom, date), domaineExpertise(expertise), nbPersonne(nbPers) {
    if (nbPersonne > 0) {
        personne = new string[nbPersonne];
        for (int i = 0; i < nbPersonne; ++i) {
            cout << "Nom de la personne " << i+1 << " : ";
            cin >> personne[i];
        }
    }
}

Humaine::~Humaine() {
    delete[] personne;
}

Humaine::Humaine(const Humaine& h):Ressource(h)
{
     domaineExpertise=h.domaineExpertise;
     nbPersonne=h.nbPersonne;
     personne = new string [nbPersonne];
     for(int i=0;i< nbPersonne;i++)
     {
         personne[i]=h.personne[i];
     }
}

Humaine& Humaine::operator=(const Humaine& h)
{
    if(this!=&h)
    {
        Ressource::operator=(h);
        domaineExpertise=h.domaineExpertise;
        nbPersonne=h.nbPersonne;
        personne=new string[nbPersonne];
        for(int i=0;i< nbPersonne;i++)
            {
         personne[i]=h.personne[i];
            }
    }
    return *this;
}

void Humaine::afficherRessource() {
    Ressource::afficherRessource();
    cout << "Domaine d'expertise : " << domaineExpertise << endl;
    cout << "Nombre de personnes : " << nbPersonne << endl;
    if (nbPersonne > 0) {
        cout << "Personnes : ";
        for (int i = 0; i < nbPersonne; ++i) {
            cout << personne[i] << ", ";
        }
        cout << endl;
    }
}

istream& operator>> (istream& in,Humaine& h)
{
    Ressource *r=&h;
    in>>*r;
    cout << "Domaine d'expertise : ";
    in >> h.domaineExpertise;
    cout << "Nombre de personnes : ";
    in >> h.nbPersonne;
    if (h.nbPersonne > 0) {
        h.personne = new string[h.nbPersonne];
        for (int i = 0; i < h.nbPersonne; ++i) {
            cout << "Nom de la personne " << i+1 << " : ";
            in >> h.personne[i];
        }
    }
    return in;
}


