#ifndef EVENT_H
#define EVENT_H
#include <iostream>
#include <vector>
#include "listeStartUp.h"
#include "startups.h"
using namespace std;
class Event
{
protected:
    int idEvent;
    string duree;
    string themeEvent;
    vector<StartUp*> tabStartUpParticipante;

public:
    Event();
    Event(int,string,string);
    virtual ~Event();
    Event(const Event&);
    Event& operator=(const Event&);
    virtual void afficherEvent()=0;
    void ajouterParticipant(int,ListeStartUps&);
    friend istream& operator>> (istream&,Event&);
    void afficherParticipant();

};
#endif
