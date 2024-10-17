#include <iostream>
#include <vector>
#include "ressource.h"
#include "financiere.h"

using namespace std;


Financiere::Financiere(){}

Financiere::Financiere(int id, string nom, string date, double montant, int nbAide)
    : Ressource(id, nom, date), montantDisponible(montant), nb_aide(nbAide) {
    aidesFinancieres = new float[nbAide];
}

Financiere::Financiere(const Financiere& fin) : Ressource(fin)
{
     montantDisponible=fin.montantDisponible;
     nb_aide=fin.nb_aide;
     aidesFinancieres = new float [nb_aide];
     for (int i=0 ;i<nb_aide;i++)
     {
         aidesFinancieres[i]=fin.aidesFinancieres[i];
     }
}

Financiere& Financiere::operator=(const Financiere& f)
{
    if (this!=&f)
    {
       Ressource::operator=(f);
        montantDisponible=f.montantDisponible;
        nb_aide=f.nb_aide;
        aidesFinancieres=new float [nb_aide];
         for (int i=0 ;i<nb_aide;i++)
        {
         aidesFinancieres[i]=f.aidesFinancieres[i];
        }
    }
    return *this;
}

Financiere::~Financiere() {
    delete[] aidesFinancieres;
}

void Financiere::afficherRessource() {
    Ressource::afficherRessource();
    cout << "Montant disponible : " << montantDisponible << endl;
}


istream& operator>> (istream& in,Financiere& f)
{
    Ressource *r=&f;
    in>>*r;
    cout << "Montant disponible : ";
    in >> f.montantDisponible;
    cout << "Nombre d'aides financieres : ";
    in >> f.nb_aide;
    f.aidesFinancieres = new float[f.nb_aide];
    cout << "Saisir les montants des aides financieres :" << endl;
    for (int i = 0; i < f.nb_aide; ++i) {
        cout << "Montant pour l'aide financiere " << i + 1 << " : ";
        in >> f.aidesFinancieres[i];
    }
    return in;
}

void Financiere::afficherAide() {
    cout << "Aides financieres :" << endl;
    for (int i = 0; i < nb_aide; ++i) {
        cout << "- Aide financiere " << i + 1 << " : " << aidesFinancieres[i] << endl;
    }
}
