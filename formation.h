#ifndef FORMATION_H
#define FORMATION_H
#include <iostream>
#include <vector>
#include "Event.h"

using namespace std;
class Formation : public Event
{
    string sujetFormation;
    string salleFormation;
    int nbIntervenant;
    string* intervenants;

public:
    Formation();
    Formation(int,string,string,string,string,int);
    ~Formation();
    Formation(const Formation&);
    Formation& operator=(const Formation&);
    void afficherEvent();
    friend istream& operator>> (istream&,Formation&);
    void afficherIntervenant();

};
#endif
