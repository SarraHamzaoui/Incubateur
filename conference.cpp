#include <iostream>
#include "conference.h"
#include "event.h"
using namespace std;

Conference::Conference(int idEvent, string duree, string themeEvent, string lieu, int nbConferencier)
    : Event(idEvent, duree, themeEvent) {
        this->lieu=lieu;
        this->nbConferencier;
    conferencier = new string[nbConferencier];
}

Conference::Conference(const Conference& c)
    : Event(c), lieu(c.lieu), nbConferencier(c.nbConferencier) {
    conferencier = new string[nbConferencier];
    for (int i = 0; i < nbConferencier; ++i) {
        this->conferencier[i] = c.conferencier[i];
    }
}


Conference& Conference::operator=(const Conference& c)
{
    if(this!=&c)
    {
         Event::operator=(c);
        lieu=c.lieu;
        nbConferencier=c.nbConferencier;
        conferencier = new string [nbConferencier];
        for (int i=0;i< nbConferencier;i++)
            {
            conferencier[i]=c.conferencier[i];
            }
    }
    return *this;
}


Conference::~Conference() {
    delete[] conferencier;
}

void Conference::afficherConferencier() {
    cout << "Conferenciers :" << endl;
    for (int i = 0; i < nbConferencier; ++i) {
        cout << conferencier[i] << endl;
    }
}

void Conference::afficherEvent() {
    Event::afficherEvent();
    cout << "Duree: " << duree << endl;
    cout << "Theme: " << themeEvent << endl;
    cout << "Lieu: " << lieu << endl;
    afficherConferencier();
}

istream& operator>> (istream& in ,Conference& c)
{
    Event *e=&c;
    in>>*e;
    cout << "Lieu de la conference : ";
    in >> c.lieu;
    cout << "Nombre de conferenciers : ";
    in >> c.nbConferencier;
    c.conferencier = new string[c.nbConferencier];
    for (int i = 0; i < c.nbConferencier; ++i) {
        cout << "Conferencier " << i + 1 << " : ";
        in >> c.conferencier[i];
    }
    return in;
}

Conference::Conference(){}


