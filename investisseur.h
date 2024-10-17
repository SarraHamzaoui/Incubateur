#ifndef INVESTISSEUR_H
#define INVESTISSEUR_H
#include <iostream>

#include <vector>
#include "ressource.h"
#include "humaine.h"

using namespace std;

class Investisseur : public Humaine {

    double fondsDisponibles;
    int nb_invest;
    string* investissements;

public:
    Investisseur();
    Investisseur(int, string, string, string, int, double, int);
    ~Investisseur();
    Investisseur(const Investisseur& );
    Investisseur& operator=(const Investisseur&);
    void afficherRessource() ;
    friend istream& operator>> (istream&,Investisseur&);
    void afficherInvestissement();
    void supprimerInvestissement(string);
    void afficherTitre();
};

#endif
