#ifndef RESSOURCE_H
#define RESSOURCE_H

#include <iostream>
#include <vector>

using namespace std;

class Ressource
{
protected:
    int id_Ressource;
    string nomRessource;
    string dateAquisition;
    string* description;

public:
    Ressource();
    Ressource(int,string,string);
    virtual ~Ressource();
    Ressource(const Ressource&);
    Ressource & operator=(const Ressource&);
    virtual void afficherRessource()=0;
    friend istream& operator>> (istream&,Ressource&);
    void AfficherDescription();
};
#endif
