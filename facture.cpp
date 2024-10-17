#include "projet.h"
#include <iostream>
#include <string>
#include <algorithm>
#include "facture.h"
#include <iterator>

using namespace std;

Facture::Facture() {
    id_facture = 0;
    prixTotal = 0.0;
    payee = false;
}
Facture::Facture(int id_facture,double prixTotal)
{
    this->id_facture=id_facture;
    this->prixTotal=prixTotal;
}
Facture::~Facture()
{

      list<Projet*>::iterator it;
      for (it=liste_projets_facture.begin(); it != liste_projets_facture.end(); ++it)
        {
            delete *it;
        }
    liste_projets_facture.clear();

}

Facture::Facture(const Facture& autre)
 {
        this->id_facture = autre.id_facture;
        this->prixTotal = autre.prixTotal;
        this->payee = autre.payee;
        list<Projet*>::iterator it;
        for (it=liste_projets_facture.begin(); it != liste_projets_facture.end(); ++it)
        {
             Projet* projet = new Projet(**it);
        liste_projets_facture.push_back(projet);
        }
}

Facture& Facture::operator=(const Facture& f)
{
    list<Projet*>::iterator it, it2;

    if (this != &f)
    {
        for (it = liste_projets_facture.begin(); it != liste_projets_facture.end(); ++it)
        {
            delete *it;
        }
        liste_projets_facture.clear();

        id_facture = f.id_facture;
        prixTotal = f.prixTotal;
        payee = f.payee;

        list<Projet*> list1 = f.liste_projets_facture;
        for (it2 = list1.begin(); it2 != list1.end(); ++it2)
        {
            liste_projets_facture.push_back(new Projet(**it2));
        }
    }
    return *this;
}


void Facture::ajouterProjet(Projet* projet)
{
       liste_projets_facture.push_back(projet);
        prixTotal += projet->getPrix();
}

 bool Facture::peutPayer(double budget)
{
        return !payee && prixTotal <= budget;
 }

 void Facture::payer()
 {
        payee = true;
}

int Facture::getIdFacture()
  {
      return this->id_facture;
  }

double Facture::getPrixTotal()
{
    return this->prixTotal;
}

  void Facture::setIdFacture() {
        id_facture = prochainId++;
    }

int Facture::prochainId = 1;

void Facture::setPrixTotal(double prix)
 {
    prixTotal = prix;
}

void Facture::setPayee(bool estPayee)
{
        payee = estPayee;
}

ostream& operator<< (ostream& out, Facture& f)
{
    out << "ID de la facture : " << f.id_facture << endl;
    return out;
}

///surcharge de +
double operator+(Facture& f1,Facture& f2)
{
    double res;
    res=f1.prixTotal+f2.prixTotal;
    return res;
}

///pour map
void Facture::ajouterFinMap(Projet* p)
{
    map<int,Projet>::iterator it;
    for(it=map1.begin();it!=map1.end();++it)
    {
        if((it->second.getIdProjet())==(p->getIdProjet()))
        {
            cout<<"l'element existe deja dans le map"<<endl;
        }
    }
    map1.insert(pair<int,Projet>(p->getIdProjet(),*p));
}

void Facture::afficherMap()
{
    Projet p3(12,"sss","bbb",15.21,1);
    map<int,Projet>::iterator it;
    it = map1.find(p3.getIdProjet());
       if (it != map1.end()) {

        cout << "le projet avec id 12 existe"<< endl;
    } else {
        cout << "\n le projet avec id 12 n'existe pas" << endl;
    }
    for (it=map1.begin();it!=map1.end();++it)
    {
        cout << it->first << ": " << it->second << endl;
        cout << "--------------------------------------" << endl;
    }
}

