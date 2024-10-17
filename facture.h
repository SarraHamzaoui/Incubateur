#ifndef FACTURE_H
#define FACTURE_H
#include <iostream>

#include<stdlib.h>
#include<string.h>
#include<vector>
#include <list>
#include <iterator>
#include<map>
#include"projet.h"

using namespace std;

class Facture
{
private:
    int id_facture;
    double prixTotal;
    bool payee;
    list<Projet*> liste_projets_facture;
    map<int,Projet>map1;
    static int prochainId;
public:

    Facture();
    Facture(int,double);
    ~Facture();
    Facture(const Facture& );
    Facture& operator=(const Facture&);
    void ajouterProjet(Projet*);
    bool peutPayer(double);
    void payer();
    int getIdFacture();
    double getPrixTotal();
    void setIdFacture( );
    void setPrixTotal(double ) ;
    void setPayee(bool);
    friend ostream& operator<< (ostream&, Facture&);
    friend double operator+(Facture&,Facture&);
    static void creeeF();
    ///pour map
    void ajouterFinMap(Projet*);
    void afficherMap();
};
#endif




