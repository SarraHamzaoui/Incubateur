#include <iostream>
#include <vector>
#include "startups.h"

#include "listeStartUp.h"
#include "event.h"

using namespace std;

Event::Event(){}

Event::Event(int idEvent,string duree,string themeEvent)
{
    this->idEvent=idEvent;
    this->duree=duree;
    this->themeEvent=themeEvent;
}
Event::~Event()
{
     for(int i=0;i<this->tabStartUpParticipante.size();i++)
      {
            delete this->tabStartUpParticipante[i];
      }
      tabStartUpParticipante.clear();
}
 Event::Event(const Event& e )
 {
     this->idEvent=e.idEvent;
     this->duree=e.duree;
     this->themeEvent=e.themeEvent;

     for (int i = 0; i < e.tabStartUpParticipante.size(); ++i)
        {
            StartUp* startup = e.tabStartUpParticipante[i];
            tabStartUpParticipante.push_back(new StartUp(*startup));
        }
 }

Event& Event::operator=(const Event& e)
{
    if(this!=&e)
    {
         idEvent=e.idEvent;
        duree=e.duree;
        themeEvent=e.themeEvent;
         for (int i=0;i< tabStartUpParticipante.size();i++)
        {
            delete tabStartUpParticipante[i];
        }
        tabStartUpParticipante.clear();
        for (int i=0;i< e.tabStartUpParticipante.size();i++)
         {
             StartUp* s=new StartUp(*e.tabStartUpParticipante[i]);
             tabStartUpParticipante.push_back(s);
         }
    }
    return *this;

}

void Event::ajouterParticipant(int idStartUp, ListeStartUps& l) {
    StartUp* startup = l.getStartUpById(idStartUp);
    if (startup != nullptr) {
        tabStartUpParticipante.push_back(startup);
        cout << "StartUp ajoutee avec succes à l'evenement." << endl;
    } else {
        cout << "Erreur : StartUp avec l'ID " << idStartUp << " non trouvee." << endl;
    }
}

istream& operator>>(istream& in, Event& e) {
    cout << "Saisie de l'evenement" << endl;

    cout << "ID de l'evenement (positif): ";
    if (!(in >> e.idEvent) || e.idEvent < 0) {
        throw "ID de l'evenement invalide.";
    }
        cout << "Duree de l'evenement : ";
            in >> e.duree;
        cout << "Theme de l'evenement : ";
    if (!(in >> e.themeEvent)) {
        throw "Theme de l'evenement invalide.";
    }

    return in;
}

void Event::afficherEvent() {
    cout << "ID de l'evenement : " << idEvent << endl;
    cout << "Duree : " << duree << endl;
    cout << "Theme : " << themeEvent << endl;
}

void Event::afficherParticipant() {
    cout << "Participants :" << endl;
    for (int i = 0; i < tabStartUpParticipante.size(); ++i) {
        cout << "StartUp " << i+1 << " : " << tabStartUpParticipante[i]->getNom_stratUp() << endl;
    }
}
