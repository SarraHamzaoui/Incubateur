
#ifndef MATERIELLE_H
#define MATERIELLE_H
#include <iostream>
#include <vector>
#include "ressource.h"

using namespace std;

class Materielle : public Ressource {
private:
    int quantiteDisponible;
    string* materielsDisponibles;

public:
    Materielle();
    Materielle(int, string, string, int);
    ~Materielle();
    Materielle(const Materielle&);
    Materielle& operator=(const Materielle&);
    void afficherRessource() ;
    friend istream& operator>> (istream&,Materielle&);
    void afficherMaterielsDisponibles();
};

#endif
