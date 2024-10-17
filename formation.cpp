#include <iostream>
#include <vector>
#include "formation.h"
#include "event.h"

using namespace std;

Formation::Formation(){}
Formation::Formation(int idEvent,string duree,string themeEvent,string sujetFormation,string salleFormation,int nbIntervenant): Event(idEvent,duree,themeEvent)
{
    this->sujetFormation=sujetFormation;
    this->salleFormation=salleFormation;
    this->nbIntervenant=nbIntervenant;
    intervenants = new string[nbIntervenant];
}
Formation::Formation(const Formation& f): Event(f)
{
    this->sujetFormation=f.sujetFormation;
    this->salleFormation=f.salleFormation;
    this->nbIntervenant=f.nbIntervenant;
    intervenants=new string [nbIntervenant];
    for (int i=0;i< nbIntervenant;i++)
    {
        this->intervenants[i]=f.intervenants[i];
    }
}

Formation& Formation::operator=(const Formation& f)
{
    if(this!=&f)
    {
         Event::operator=(f);
        sujetFormation=f.sujetFormation;
        salleFormation=f.salleFormation;
        nbIntervenant=f.nbIntervenant;
        intervenants = new string [nbIntervenant];
        for (int i=0;i< nbIntervenant;i++)
            {
            intervenants[i]=f.intervenants[i];
            }
    }
    return *this;
}

Formation::~Formation() {
    delete[] intervenants;
}

void Formation::afficherIntervenant() {
    cout << "Intervenants :" << endl;
    for (int i = 0; i < nbIntervenant; ++i) {
        cout << intervenants[i] << endl;
    }
}

void Formation::afficherEvent() {
    Event::afficherEvent();
    cout << "Duree: " << duree << endl;
    cout << "Theme: " << themeEvent << endl;
    cout << "Sujet: " << sujetFormation << endl;
    cout << "Salle: " << salleFormation << endl;
    afficherIntervenant();
}

istream& operator>> (istream& in ,Formation&  f )
{
    Event *e=&f;
    in>>*e;
    cout << "Sujet de la formation : ";
    in >> f.sujetFormation;
    cout << "Salle de la formation : ";
    in >> f.salleFormation;
    cout << "Nombre d'intervenants : ";
    in >> f.nbIntervenant;
    f.intervenants = new string[f.nbIntervenant];
    for (int i = 0; i < f.nbIntervenant; ++i) {
        cout << "Intervenant " << i+1 << " : ";
        in >> f.intervenants[i];
    }
    return in;
}











