#include <iostream>
#include <vector>
#include "ressource.h"
#include "humaine.h"
#include "investisseur.h"

using namespace std;

Mentor::Mentor(){}

Mentor::Mentor(int id, string nom, string date, string expertise, int nbPers, int session)
    : Humaine(id, nom, date, expertise, nbPers), nombreSessions(session) {
    if (nombreSessions > 0) {
        this->session = new string[nombreSessions];
        for (int i = 0; i < nombreSessions; ++i) {
            cout << "Session " << i + 1 << " : ";
            cin >> this->session[i];
        }
    }
}

Mentor::~Mentor() {
    delete[] session;
}

void Mentor::afficherRessource() {
    Humaine::afficherRessource();
    cout << "Nombre de sessions de mentorat : " << nombreSessions << endl;
    if (nombreSessions > 0) {
        cout << "Sessions :" << endl;
        for (int i = 0; i < nombreSessions; ++i) {
            cout << "- " << session[i] << endl;
        }
    }
}

istream& operator>>(istream& in ,Mentor& m)
{
    Humaine *h=&m;
    in>>*h;
    cout << "Nombre de sessions de mentorat : ";
    in >> m.nombreSessions;
    if (m.nombreSessions > 0) {
        m.session = new string[m.nombreSessions];
        for (int i = 0; i < m.nombreSessions; ++i) {
            cout << "Session " << i + 1 << " : ";
            in >> m.session[i];
        }
    }
    return in;
}

void Mentor::afficherSessions() {
    cout << "Sessions :" << endl;
    for (int i = 0; i < nombreSessions; ++i) {
        cout << "- " << session[i] << endl;
    }
}

void Mentor::supprimerSession() {
    if (nombreSessions == 0) {
        cout << "Aucune session a supprimer." << endl;
        return;
    }

    string sessionASupprimer;
    cout << "Entrez le nom de la session a supprimer : ";
    cin >> sessionASupprimer;

    bool trouve = false;
    for (int i = 0; i < nombreSessions; ++i) {
        if (session[i] == sessionASupprimer) {
            trouve = true;
            for (int j = i; j < nombreSessions - 1; ++j) {
                session[j] = session[j + 1];
            }
            nombreSessions--;
            break;
        }
    }

    if (!trouve) {
        cout << "La session specifiee n'a pas ete trouvee." << endl;
    }
}

 void Mentor::afficherTitre()  {
        cout << "Mentor" << endl;
    }


Mentor::Mentor(const Mentor& m) : Humaine(m) {
    nombreSessions = m.nombreSessions;

        session = new string[nombreSessions];
        for (int i = 0; i < nombreSessions; ++i) {
            session[i] = m.session[i];
        }
}

Mentor& Mentor::operator=(const Mentor& m) {

    if (this != &m) {
        Humaine::operator=(m);
        nombreSessions = m.nombreSessions;
            session = new string[nombreSessions];
            for (int i = 0; i < nombreSessions; ++i) {
                session[i] = m.session[i];
        }
    }
    return *this;
}


