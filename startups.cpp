#include "projet.h"
#include <iostream>
#include <string>
#include<istream>
#include<ostream>
#include<fstream>
#include <sstream>
#include "facture.h"
#include "startups.h"

using namespace std;

StartUp::StartUp(){}
StartUp::StartUp(int id_startUp,string nom_stratUp,string nom_fondateur,string domaine_activite,float budget  ,int anneeCreation) {
    this->id_startUp = id_startUp;
    this->nom_stratUp = nom_stratUp;
    this->nom_fondateur = nom_fondateur;
    this->domaine_activite = domaine_activite;
    this->budget=budget ;
    this->anneeCreation = anneeCreation;
}

istream& operator>> (istream& in, StartUp& s)
{
    try {
        cout << "Saisir l'ID de la startup (positif) : ";
        in >> s.id_startUp;
        if (s.id_startUp < 0) {
            throw "L'ID de la startup doit etre un nombre positif.";
        }
        cout << "Nom de la startup : ";
        in >> s.nom_stratUp;

        cout << "Nom du fondateur : ";
        in >> s.nom_fondateur;

        cout << "Domaine d'activite : ";
        in >> s.domaine_activite;

        cout << "Le budget : ";
        in >> s.budget;
        if (s.budget < 0) {
            throw "Le budget de la startup doit etre un nombre positif.";
        }

        cout << "Annee de creation : ";
        in >> s.anneeCreation;
        if (s.anneeCreation < 0) {
            throw "L'annee de creation de la startup doit etre un nombre positif.";
        }
        cout << "Saisie avec succes"<<endl;
    } catch (const char* message) {
            throw message;
        }
    return in;
}

 ostream& operator<< (ostream& out,StartUp& s)
{
    out << "ID : " << s.id_startUp << endl;
    out << "Nom : " << s.nom_stratUp << endl;
    out << "Fondateur : " << s.nom_fondateur << endl;
    out << "Domaine : " << s.domaine_activite << endl;
    out << "Budget  : " << s.budget  << endl;
    out << "Annee de creation : " << s.anneeCreation << endl;
    //nbStartUptot++;
    return out;
}

string StartUp::getNom_stratUp()
{
    return this->nom_stratUp;
}
int StartUp::getId_startUp()
{
    return this->id_startUp;
}
void StartUp::creer(fstream& f)
{
    f.open("startUps.txt", ios::in |ios::out |ios::trunc);
    if(! f.is_open()) exit(-1);
}
void StartUp::remplir(fstream& f)
{
    ofstream fichier("startUps.txt", ios::app);
    if (fichier.is_open()) {
        fichier << this->id_startUp << ' ' << this->nom_stratUp << ' ' << this->nom_fondateur << ' ' << this->domaine_activite << ' ' << this->budget << ' ' << this->anneeCreation << endl;
        fichier.close();
        cout << "Donnees remplies avec succes "<< endl;
    } else {
        cerr << "Impossible d'ouvrir le fichier : " <<endl;
    }
}


int StartUp::chercher(ifstream& fichier, int id) {
    int ligne = 0;
    string line;

    while (getline(fichier, line)) {
        stringstream ss(line);
        int startupId;
        ss >> startupId;

        if (startupId == id) {
            return ligne;
        }
        ++ligne;
    }

    return -1;
}

void StartUp::supprimerStratUpsfichier(fstream& fichier, int id_supp) {
    ofstream tempFile("temp.txt");
    ifstream originalFile("startUps.txt");
    if (tempFile.is_open() && originalFile.is_open()) {
        string ligne;
        int ligneASupprimer = chercher(originalFile, id_supp);

        if (ligneASupprimer == -1) {
            cout << "La startup a supprimer n'existe pas." << endl;
            return;
        }

        originalFile.clear();
        originalFile.seekg(0);

        int compteur = 0;
        while (getline(originalFile, ligne)) {
            if (compteur != ligneASupprimer) {
                tempFile << ligne << endl;
            }
            ++compteur;
        }

        originalFile.close();
        tempFile.close();

        originalFile.close();

        remove("startUps.txt");
        rename("temp.txt", "startUps.txt");

        cout << "La startup a ete supprimee avec succes." << endl;
    } else {
        cerr << "Erreur lors de l'ouverture des fichiers." << endl;
    }
}

void StartUp::afficherFichier(ifstream& fichier) {
    if (fichier.is_open()) {
        string ligne;
        int numeroLigne = 1;
        while (getline(fichier, ligne)) {
            cout << "Ligne " << numeroLigne << ": " << ligne << endl;
            numeroLigne++;
        }
        fichier.close();
    } else {
        cerr << "Impossible d'ouvrir le fichier." << endl;
    }
}
///****************Projet***********************

void StartUp::ajouterProjet(const Projet projet) {
    this->tabProjet.push_back(new Projet(projet));
}

//creation fichier projet
void StartUp::creerP(fstream& f)
{
    f.open("projet.txt", ios::in |ios::out |ios::trunc);
    if(! f.is_open()) exit(-1);
}
//destructeur
StartUp::~StartUp()
{
     for(int i=0;i<this->tabProjet.size();i++)
      {
            delete this->tabProjet[i];
      }
      tabProjet.clear();


      for (int i = 0; i < tabRessource.size(); ++i) {
        delete tabRessource[i];
    }

    tabRessource.clear();
}
//recopie
StartUp::StartUp(const StartUp& s)
{
    Ressource *e;
    this->id_startUp=s.id_startUp;
    this->nom_stratUp=s.nom_stratUp;
    this->nom_fondateur=s.nom_fondateur;
    this->domaine_activite=s.domaine_activite;
    this->budget=s.budget;
    this->anneeCreation=s.anneeCreation;
    for (int i = 0; i < s.tabProjet.size(); i++) {
        Projet* nouveauProjet = new Projet(*s.tabProjet[i]);
        this->tabProjet.push_back(nouveauProjet);
    }
    //pour les ressources
    for(int i=0;i<s.tabRessource.size();i++)
    {
        if(typeid(*s.tabRessource[i])== typeid(Investisseur))
            e=new Investisseur(static_cast <const Investisseur&> (*s.tabRessource[i]));
        else if(typeid(*s.tabRessource[i])== typeid(Mentor))
            e=new Mentor(static_cast <const Mentor&> (*s.tabRessource[i]));
        else if(typeid(*s.tabRessource[i])== typeid(Financiere))
            e=new Financiere(static_cast <const Financiere&> (*s.tabRessource[i]));
        else if(typeid(*s.tabRessource[i])== typeid(Materielle))
            e=new Materielle(static_cast <const Materielle&> (*s.tabRessource[i]));

        tabRessource.push_back(e);
    }
}
// surchage de l'affectation =
StartUp& StartUp ::operator=(const StartUp& s)
{
    if (this != &s)
    {
        for ( int i=0;i<tabProjet.size();i++)
            {
            delete tabProjet[i];
            }
        tabProjet.clear();
        this->id_startUp=s.id_startUp;
        this->nom_stratUp=s.nom_stratUp;
        this->nom_fondateur=s.nom_fondateur;
        this->domaine_activite=s.domaine_activite;
        this->budget=s.budget;
        this->anneeCreation=s.anneeCreation;
        for ( int i=0;i<s.tabProjet.size();i++)
        {
            Projet* nouveauProjet = new Projet(*s.tabProjet[i]);
            this->tabProjet.push_back(nouveauProjet);
        }
    }
    return *this;
}

const vector<Projet*>& StartUp::getTabProjet() const {
        return tabProjet;
    }
///--------------------------Facture----------------------------------

// Afficher les détails de la facture
void StartUp::afficherFacture() {
    cout << "Facture pour la StartUp " << this->nom_stratUp << ":" << endl;
    cout<<facture;
    cout << "Prix total : " << this->facture.getPrixTotal() << " dinars" << endl;
    cout << "La facture est " << (facture.peutPayer(budget) ? "payable" : "non payable") << " avec un budget de " << budget << endl;

}
// Ajouter un projet à la facture
void StartUp::ajouterProjetAFacture(Projet* projet) {
    this->facture.ajouterProjet(projet);
}
// Vérifier si la startup peut payer la facture
bool StartUp::peutPayerFacture() {
    if (budget >= facture.getPrixTotal() && !facture.peutPayer(budget)) {
        return true;
    }
    return false;
}
///--------------------------------Ressource-------

void StartUp::afficherTabRessource()
{
    cout << "Ressources allouees à la StartUp :" << endl;
    for (int i = 0; i < tabRessource.size(); i++)
    {
        cout << "-----------------------------------------" << endl;
        cout << "Ressource #" << i + 1 << ":" << endl;
        cout << "Type de ressource : ";
        if (typeid(*tabRessource[i])==typeid(Investisseur)) {
            cout << "Investisseur" << endl;
        } else if (typeid(*tabRessource[i])==typeid(Mentor)) {
            cout << "Mentor" << endl;
        } else if (typeid(*tabRessource[i])==typeid(Financiere)) {
            cout << "Ressource financiere" << endl;
        } else if (typeid(*tabRessource[i])==typeid(Materielle)) {
            cout << "Ressource materielle" << endl;
        } else {
            cout << "Type de ressource inconnu" << endl;
        }
        tabRessource[i]->afficherRessource();
        cout << "-----------------------------------------" << endl;
    }
}

void StartUp::remplirTabRessource()
{
    char rep;
    Investisseur* inv;
    Mentor* m;
    Financiere* f;
    Materielle* mat;
    int choix;
    do
    {
        cout<<"\n taper 1: Investisseur, taper 2: Mentor, taper 3: Financiere, taper 4: Materielle"<<endl;
        cin>>choix;
        if(choix==1)
        {
            inv=new Investisseur();
            cin >> *inv;
            tabRessource.push_back(inv);
        }

        else if (choix==2)
        {
            m=new Mentor();
            cin >> *m;
            tabRessource.push_back(m);
        }

        else if (choix==3)
        {
            f=new Financiere();
            cin >> *f;
            tabRessource.push_back(f);
        }

        else if (choix==4)
        {
            mat=new Materielle();
            cin >> *mat;
            tabRessource.push_back(mat);
        }

        else break;
        cout<<"\n rajouter ?"<<endl;
        cin>> rep;
    }while(rep=='o'|| rep=='O');
}

void StartUp::ajouterRessource(Investisseur* q)
{
    tabRessource.push_back(q);
}


void StartUp::ajouterRessource(Mentor* q)
{
    tabRessource.push_back(q);
}

void StartUp::ajouterRessource(Financiere* q)
{
    tabRessource.push_back(q);
}

void StartUp::ajouterRessource(Materielle* q)
{
    tabRessource.push_back(q);
}

void StartUp::supprimerRessource (int ind )
{
    delete tabRessource[ind];
    tabRessource.erase(tabRessource.begin()+ind);
}

Projet StartUp::operator[](int i)
{
    return *tabProjet[i];
}

void StartUp::creerFacture(ofstream& fichier) {
    double prixTotal = 0.0;
    for (int i = 0; i < tabProjet.size(); ++i) {
        prixTotal += tabProjet[i]->getPrix();
    }
    facture.setIdFacture();
    facture.setPrixTotal(prixTotal);
    facture.setPayee(false);

    // Écriture des détails de la facture dans le fichier
    fichier << "ID Facture : " << facture.getIdFacture() << endl;
    fichier << "Prix Total : " << facture.getPrixTotal() << endl;
    fichier << "Payee : " << (facture.peutPayer(budget) ? "payable" : "non payable") << endl;

    fichier << "---------------------------" << endl;
}

int StartUp::nbStartUptot = 0;
void StartUp::setnbTot()
{
    this->nbtot=nbStartUptot++;
}
int StartUp::getNbtot()
{
    return nbtot;
}
