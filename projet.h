#ifndef PROJET_H
#define PROJET_H
#include <iostream>
#include<ostream>
#include<istream>
#include<stdlib.h>
#include<string.h>

using namespace std;

class Projet
{
private:
    int id_projet;
    string nom_projet;
    string objectif;
    double prix;
    int etape_dev;
public:
    Projet();
    Projet(int,string,string,double,int);
    ~Projet();
    int getIdProjet();
    double getPrix();
    string getNomProjet();
    ///surcharge
    friend ostream& operator<< (ostream&,Projet&);//afficher
    friend istream& operator>> (istream&,Projet&);//saisie
};
#endif



