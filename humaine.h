#ifndef HUMAINE_H
#define HUMAINE_H
#include <iostream>
#include <vector>
#include "ressource.h"

using namespace std;

class Humaine : public Ressource
{
protected:
    string domaineExpertise;
    int nbPersonne;
    string* personne;
public:
    Humaine();
    Humaine(int,string,string,string,int);
    virtual ~Humaine();
    Humaine(const Humaine& );
    Humaine& operator=(const Humaine&);
    void afficherRessource();
    friend istream& operator>> (istream&,Humaine&);
    virtual void afficherTitre() = 0;//je vais pas l'utiliser
};
#endif
