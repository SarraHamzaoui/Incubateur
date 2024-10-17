#ifndef LISTE_STARTUPS_H
#define LISTE_STARTUPS_H
#include <iostream>
#include <vector>
#include<map>

#include "startups.h"
#include "projet.h"

using namespace std;
class ListeStartUps
{
private:
     list<StartUp*> listeStratUp;
     map<int,StartUp>map1;
public:
    ListeStartUps();
    ~ListeStartUps();
    ListeStartUps(const ListeStartUps& );
    ListeStartUps& operator=(const ListeStartUps&);
    void ajouterStartUp( StartUp*);
    void affecterProjet(int,Projet*);
    void afficherProjetsDeStartUp(int );
    void remplirProjetsDeStartUp(int , ofstream& );
    StartUp* getStartUp(int ) const;
    int tailleTabStratUp() const ;
    void remplirFichierProjets(ofstream& );
    void afficherFacturesDeStartUp(int);//a enlever car ilna pas d'implementation
    StartUp* getStartUpById(int ) ;
    ///POUR LE MAP
    void ajouterFinMap(StartUp*);
    void afficherMap();
};
#endif
