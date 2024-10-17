#include <iostream>
#include <vector>
#include "ressource.h"
#include "humaine.h"
#include "investisseur.h"

using namespace std;

Investisseur::Investisseur(){}

Investisseur::Investisseur(int id, string nom, string date, string expertise, int nbPers, double fonds, int nbInvest)
    : Humaine(id, nom, date, expertise, nbPers), fondsDisponibles(fonds), nb_invest(nbInvest) {
    investissements = new string[nb_invest];
}

Investisseur::~Investisseur() {
    delete[] investissements;
}

Investisseur::Investisseur(const Investisseur& inv ): Humaine(inv)
{
    fondsDisponibles=inv.fondsDisponibles;
    nb_invest=inv.nb_invest;
    investissements = new string[nb_invest];
        for (int i = 0; i < nb_invest; i++) {
            investissements[i] = inv.investissements[i];
        }
}
Investisseur& Investisseur::operator=(const Investisseur& inv)
{
    if(this!=&inv)
    {
        Humaine::operator=(inv);
        fondsDisponibles=inv.fondsDisponibles;
        nb_invest=inv.nb_invest;
        investissements = new string [nb_invest];
        for (int i = 0; i < nb_invest; i++) {
            investissements[i] = inv.investissements[i];
        }
    }
    return *this;
}
void Investisseur::afficherRessource() {
    Humaine::afficherRessource();
    cout << "Fonds disponibles : " << fondsDisponibles << endl;
    cout << "Nombre d'investissements : " << nb_invest << endl;
    if (investissements != nullptr) {
        cout << "Investissements :" << endl;
        for (int i = 0; i < nb_invest; ++i) {
            cout << "- " << investissements[i] << endl;
        }
    }
}

istream& operator>> (istream& in,Investisseur& inv)
{
    Humaine *h=&inv;
    in>>*h;
    cout << "Fonds disponibles : ";
    in >> inv.fondsDisponibles;
    cout << "Nombre d'investissements : ";
    in >> inv.nb_invest;
    inv.investissements = new string[inv.nb_invest];
    for (int i = 0; i < inv.nb_invest; ++i) {
        cout << "Investissement " << i+1 << " : ";
        in >> inv.investissements[i];
    }
    return in;
}

void Investisseur::afficherInvestissement() {
    cout << "Investissements :" << endl;
    for (int i = 0; i < nb_invest; ++i) {
        cout << "- " << investissements[i] << endl;
    }
}

void Investisseur::supprimerInvestissement(string investissement) {
    // Trouver l'investissement à supprimer
    int index = -1;
    for (int i = 0; i < nb_invest; ++i) {
        if (investissements[i] == investissement) {
            index = i;
            break;
        }
    }

    // Supprimer l'investissement si trouvé
    if (index != -1) {
        string* new_investissements = new string[nb_invest - 1];
        for (int i = 0, j = 0; i < nb_invest; ++i) {
            if (i != index) {
                new_investissements[j++] = investissements[i];
            }
        }
        delete[] investissements;
        investissements = new_investissements;
        nb_invest--;
    } else {
        cout << "Investissement non trouve." << endl;
    }
}

 void Investisseur::afficherTitre()  {
        cout << "Investisseur" << endl;
    }
