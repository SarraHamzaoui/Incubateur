#ifndef STARTUP_H
#define STARTUP_H

#pragma once
#include <iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<vector>

#include"projet.h"
#include "facture.h"
#include "ressource.h"
#include "humaine.h"

#include "mentor.h"
#include "investisseur.h"
#include "materielle.h"
#include "financiere.h"

using namespace std;

class StartUp
{
private:
        int id_startUp;
        string nom_stratUp;
        string nom_fondateur;
        string domaine_activite;
        float budget ;
        int anneeCreation;
        vector<Projet*> tabProjet;
        Facture facture;
        vector<Ressource*> tabRessource;
        static int nbStartUptot;
        int nbtot;

public:

    StartUp();
    StartUp(int,string,string,string,float,int);
    //destructeur
    ~StartUp();
    //recopie
    StartUp(const StartUp& );
    friend istream& operator>> (istream&,StartUp&);//saisie
    friend ostream& operator<< (ostream&,StartUp&);//affichage
    string getNom_stratUp();
    int getId_startUp();
    static void creer(fstream&);//creation de fichier startUp
    static void creerP(fstream&);//creation fichier projet
    void remplir(fstream&);//remplissage fichier
    void remplirP(fstream&);//remplissage fichier
    friend void ajouterStartUpsfichier(fstream&,StartUp);
    static void supprimerStratUpsfichier(fstream&,int);
    static void afficherFichier(ifstream&);
    static int chercher(ifstream&,int);
    void ajouterProjet(const Projet );
    ///surcharge de l'operateur=
    StartUp & operator=(const StartUp&);
    ///surcharge de l'operateur[]
    Projet operator[](int);
    const vector<Projet*>& getTabProjet() const;
    /// Méthodes pour gérer la facture
    //void creerFacture(); // Créer une nouvelle facture pour la startup
    void creerFacture(ofstream&);
    void afficherFacture(); // Afficher les détails de la facture
    void ajouterProjetAFacture(Projet* projet); // Ajouter un projet à la facture
    bool peutPayerFacture(); // Vérifier si la startup peut payer la facture
    ///methode reltive ressources
    void remplirTabRessource ();
    void afficherTabRessource ();
    int tailleTabRessource(){return tabRessource.size();}
    void ajouterRessource(Investisseur*);
    void ajouterRessource(Mentor*);
    void ajouterRessource(Financiere*);
    void ajouterRessource(Materielle*);
    void supprimerRessource (int=0);

    void setnbTot();
    int getNbtot();
};
#endif
