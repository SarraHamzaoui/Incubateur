#ifndef CONFERENCE_H
#define CONFERENCE_H
#include <iostream>
#include <vector>
#include "Event.h"

using namespace std;
class Conference : public Event
{
    string lieu;
    int nbConferencier;
    string* conferencier;
public:
    Conference(int,string,string,string,int);
    Conference();
    ~Conference();
    Conference(const Conference&);
    Conference& operator=(const Conference&);
    void afficherEvent();
    friend istream& operator>> (istream&,Conference&);
    void afficherConferencier();
};
#endif
