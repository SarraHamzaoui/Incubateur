#ifndef MENTOR_H
#define MENTOR_H
#include <iostream>
#include <vector>
#include "ressource.h"
#include "humaine.h"

using namespace std;

class Mentor : public Humaine {
private:
    int nombreSessions;
    string* session;
public:
    Mentor();
    Mentor(int, string, string, string, int, int);
    ~Mentor();
    Mentor(const Mentor&);
    Mentor & operator=(const Mentor&);
    void afficherRessource() ;
    friend istream& operator>>(istream&,Mentor&);
    void afficherSessions();
    void supprimerSession();
    void afficherTitre();
};
#endif
