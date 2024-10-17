#ifndef FINANCIERE_H
#define FINANCIERE_H
#include <iostream>
#include <vector>
#include "ressource.h"

using namespace std;

class Financiere : public Ressource
 {
private:

    double montantDisponible;
    int  nb_aide;
    float* aidesFinancieres;
public:
    Financiere();
    Financiere(int, string, string, double, int);
    ~Financiere();
    Financiere(const Financiere& );
    Financiere& operator=(const Financiere&);
    void afficherRessource();
    friend istream& operator>> (istream&,Financiere&);
    void afficherAide();
};
#endif
