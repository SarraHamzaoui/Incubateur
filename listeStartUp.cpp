#include <iostream>
#include <vector>
#include <algorithm>
#include "startups.h"
#include <fstream>
#include "listeStartUp.h"
#include <iterator>
#include <map>
#include <iomanip>

using namespace std;

ListeStartUps::ListeStartUps() {}
//destructeur
ListeStartUps::~ListeStartUps()
{
    list<StartUp*>::iterator it;
      for( it = listeStratUp.begin(); it != listeStratUp.end(); ++it) {
        delete *it;
    }
    listeStratUp.clear();
}
//recopie
 ListeStartUps::ListeStartUps(const ListeStartUps& l )
 {
     list<StartUp*>::iterator it;
     list<StartUp*> list1 = l.listeStratUp;
     for ( it = list1.begin(); it != list1.end(); ++it) {
        StartUp* nouveauStartUp = new StartUp(**it);
        listeStratUp.push_back(nouveauStartUp);
    }
 }
//surcharge op=
ListeStartUps&  ListeStartUps::operator=(const ListeStartUps& l)
{
    list<StartUp*>::iterator it;
   if(this != &l) {
        for ( it = listeStratUp.begin(); it != listeStratUp.end(); ++it) {
            delete *it;
        }
        listeStratUp.clear();
        list<StartUp*> list1 = l.listeStratUp;
        for ( it = list1.begin(); it != list1.end(); ++it) {
            StartUp* nouveauStartUp = new StartUp(**it);
            listeStratUp.push_back(nouveauStartUp);
        }
    }
    return *this;
}

 void ListeStartUps::ajouterStartUp(StartUp* startup) {
        listeStratUp.push_back(startup);
    }

void ListeStartUps::affecterProjet(int idStartup, Projet* projet) {

    list<StartUp*>::iterator it;

    for( it = listeStratUp.begin(); it != listeStratUp.end(); ++it)
    {

        if ((*it)->getId_startUp() == idStartup) {
            (*it)->ajouterProjet(*projet);
        }
    }
}

void ListeStartUps::afficherProjetsDeStartUp(int idStartup) {
    bool startupTrouvee = false;
    list<StartUp*>::iterator it;
    for( it = listeStratUp.begin(); it != listeStratUp.end(); ++it)
        {
        if ((*it)->getId_startUp() == idStartup) {
            startupTrouvee = true;
            const vector<Projet*>& projets = (*it)->getTabProjet();
            for (int j = 0; j < projets.size(); ++j) {
                cout << *(projets[j]) << endl;
            }
            break;
        }
    }
    if (!startupTrouvee) {
        cout << "StartUp avec l'ID " << idStartup << " non trouvee." << endl;
    }
}

 int ListeStartUps::tailleTabStratUp() const {
        return listeStratUp.size();
    }

 StartUp* ListeStartUps::getStartUp(int index) const {
         if (index < 0) {
        return nullptr;
        }

        auto it = listeStratUp.begin();
        advance(it, index);

        if (it != listeStratUp.end()) {
        return *it;
        } else {
            return nullptr;
        }
    }

void ListeStartUps::remplirFichierProjets(ofstream& fichier) {

    list<StartUp*>::iterator it;
    for(it = listeStratUp.begin(); it != listeStratUp.end(); ++it) {
        StartUp& startup = **it;

        fichier << "StartUp: " << startup.getNom_stratUp() << endl;

        const vector<Projet*>& projets = startup.getTabProjet();
        for (int j = 0; j < projets.size(); ++j) {
            fichier << "Projet: " << projets[j]->getNomProjet() << endl;
        }
        fichier << endl;
    }

}

StartUp* ListeStartUps::getStartUpById(int id)  {
    list<StartUp*>::iterator it;
    for( it = listeStratUp.begin(); it != listeStratUp.end(); ++it) {
        if ((*it)->getId_startUp() == id) {
            return *it;
        }
    }
    return nullptr;
}

///pour map
void ListeStartUps::ajouterFinMap(StartUp* s)
{
    map<int,StartUp>::iterator it;
    for(it=map1.begin();it!=map1.end();++it)
    {
        if((it->second.getId_startUp())==(s->getId_startUp()))
        {
            cout<<"l'element existe deja dans le map"<<endl;
        }
    }
    map1.insert(pair<int,StartUp>(s->getId_startUp(),*s));
}

void ListeStartUps::afficherMap()
{

    StartUp s5(16,"sarra","ilef","xxx",18.5,1111);

    map<int,StartUp>::iterator it;
     it = map1.find(s5.getId_startUp());
       if (it != map1.end()) {

        cout << "la startUp avec id 16 existe"<< endl;
    } else {
        cout << "\n Cette startUp avec id 16 n'existe pas" << endl;
    }

    for (it=map1.begin();it!=map1.end();++it)
    {

        cout << it->first << ": " << it->second << endl;
        cout << "--------------------------------------" << endl;

    }

}


