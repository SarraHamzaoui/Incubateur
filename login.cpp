#include <iostream>
#include "login.h"
#include "startups.cpp"
#include "projet.cpp"
#include "listeStartUp.cpp"
#include "facture.cpp"
#include "event.cpp"
#include "formation.h"
#include "formation.cpp"
#include "conference.h"
#include "conference.cpp"
#include "mentor.h"
#include "investisseur.h"
#include "materielle.h"
#include "financiere.h"
#include "mentor.cpp"
#include "investisseur.cpp"
#include "materielle.cpp"
#include "financiere.cpp"
#include "humaine.h"
#include "humaine.cpp"
#include "ressource.h"
#include "ressource.cpp"

#include <istream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
using namespace std;

void login()
{
    int test = 0;
    int test2 = 0;
    int id_supp,id,idd,idpp;
    fstream fichierS,fichierP;
    ofstream fichier3;
    ifstream fichier,fichier2;
    StartUp s1;
    Projet p1;
    bool menuAdmin = true;
    bool menuEmp = true;
    bool retourMenu5 = false;
    bool retourMenu4 = false;
    bool retourMenu3 = false;
    bool retourMenu2 = false;
    bool retourMenu = false;
    bool testt = false;
    bool testt2 = false;
    ListeStartUps liste;

    Facture f1(100,500);
    Facture f2(120,1000);
    Facture f3;
    Formation* formationEvent;
    Conference* ConferenceEvent;
    int idStartUp8;
    int choix, choix2, choix3,choix4,choix6,choix5,choixEmp;
    int choixFacture;
    int choixRessource;
    string admin, au, admin_pass, ap, user, pass, u, p;
    char rep;
    system("cls");
    cout << "***********************************************************************\n\n\n";
    cout << "                      Bienvenue sur la page de connexion                               \n\n";
    cout << "*******************        MENU        *******************************\n\n";
    cout << "1. Se connecter en tant qu'administrateur:" << endl;
    cout << "2. Se connecter en tant qu'employe:" << endl;
    cout << "\nEntrez votre choix :";
    cin >> choix;
    cout << endl;

    ifstream input_admin;
    ifstream input_employe;

    switch (choix)
    {
    case 1:
        cout << "Veuillez entrer les donnees suivantes :" << endl;
        cout << "NOM ADMINISTRATEUR :";
        cin >> admin;
        cout << "MOT DE PASSE ADMINISTRATEUR :";
        cin >> admin_pass;

        input_admin.open("admin.txt");
        while (input_admin >> au >> ap)
        {
            if (au == admin && ap == admin_pass)
            {
                test = 1;
                system("cls");
                break;
            }
        }
        input_admin.close();

        if (test == 1)
        {

            cout << "\nBienvenue " << admin << "\n<AUTHENTIFICATION REUSSIE>\n";
            cin.get();
            cout << "***********************************************************************\n\n\n";
            cout << "                      Bienvenue sur la page de l'administrateur                               \n\n";
            while (menuAdmin)
            {
                cout << "*******************        MENU        *******************************\n\n";
                cout << "1. Gerer les projets" << endl;
                cout << "2. Gerer les factures" << endl;
                cout << "3. Organiser evenement " << endl;
                cout << "4. Gerer StratUps" << endl;
                cout << "5. Allouer ressources " << endl;
                cout << "\nEntrez votre choix ";
                cin >> choix2;

                switch (choix2)
                {

                case 1:

                    do
                    {
                        cout << "***********************************************************************\n\n\n";
                        cout << "                      Bienvenue sur la page de gestion des projets                               \n\n";
                        cout << "*******************        MENU        *******************************\n\n";
                        cout << "1. Saisie de projet et affectation au StartUp" << endl;
                        cout << "2. Remplir le fichier Projet" << endl;
                        cout << "3. Afficher le fichier Projet " << endl;
                        cout << "4. Afficher les projets relative a une startUp " << endl;
                        cout << "5. Afficher le 1er projet" << endl;
                        //cout << "6. Afficher le map" << endl;
                        cout << "6. Quitter " << endl;
                        cout << "\nEntrez votre choix : ";
                        cin >> choix4;

                        switch (choix4)
                        {

                        case 1:
                            {try {
                                int idStartUp3;
                                cout << "Entrez l'ID de la StartUp : ";
                                cin >> idStartUp3;

                                bool startUpTrouvee2 = false;
                                for (int i = 0; i < liste.tailleTabStratUp(); ++i) {
                                    StartUp* startUp = liste.getStartUp(i);
                                    if (startUp->getId_startUp() == idStartUp3) {
                                        startUpTrouvee2 = true;

                                        int nombreProjets;
                                        cout << "Entrez le nombre de projets associés à la StartUp : ";
                                        cin >> nombreProjets;

                                        for (int j = 0; j < nombreProjets; ++j) {
                                            Projet nouveau_projet;
                                            //nouveau_projet.saisie_projet();
                                            cin>>nouveau_projet;
                                            startUp->ajouterProjet(nouveau_projet);
                                            f3.ajouterFinMap(&nouveau_projet);
                                            //startUp->ajouterProjetAFacture(&nouveau_projet);

                                        }

                                        cout << "Projets ajoutés avec succès à la StartUp." << endl;
                                        break;
                                    }
                                }

                                if (!startUpTrouvee2) {
                                    cout << "StartUp avec l'ID " << idStartUp3 << " non trouvée." << endl;
                                }

                                } catch (const char* message) {

                                            cerr << "Erreur : " << message << endl;
                                    }
                                break;
                            }

                        case 2:
                            {
                                // Ouvrir le fichier en mode écriture
                                ofstream fichier("projets.txt");

                                // Vérifier si le fichier est ouvert
                                if (fichier.is_open()) {
                                    // Remplir le fichier avec les projets associés à chaque StartUp
                                    liste.remplirFichierProjets(fichier);
                                    // Fermer le fichier
                                    fichier.close();
                                } else {
                                    cerr << "Impossible d'ouvrir le fichier." << endl;
                                }
                                break;
                            }

                        case 3:
                            fichier2.open("projets.txt"); // Ouvrir le fichier avant de l'utiliser
                            StartUp::afficherFichier(fichier2);
                            break;
                        case 4:
                            {
                                int idStartup;
                                cout << "Entrez l'ID de la StartUp dont vous voulez afficher les projets : ";
                                cin >> idStartup;
                                liste.afficherProjetsDeStartUp(idStartup);
                                break;
                            }


                              case 5:
                                          {
                                              int idStartUp9;
                                              cout << "Entrez l'ID de la StartUp pour afficher son 1er projet  : ";
                                         cin >> idStartUp9;

                                        StartUp* startUp = nullptr;
                                        for (int i = 0; i < liste.tailleTabStratUp(); ++i) {
                                            if (liste.getStartUp(i)->getId_startUp() == idStartUp9) {
                                                startUp = liste.getStartUp(i);
                                                break;
                                            }
                                        }
                                        cout << "le 1er projet est:" << endl;
                                        cout<<*(startUp->getTabProjet()[0]);
                                        break;

                                          }
                       /* case 6:
                             f3.afficherMap();
                            break;*/
                        case 6:
                             retourMenu2 = true;
                            break;

                        default:
                            cout << "Choix invalide. Veuillez reessayer.\n";
                        }
                    }while (!retourMenu2);
                    retourMenu2 = false;

                    break;

                case 2:
                   do
                    {

                         cout << "***********************************************************************\n\n\n";
                        cout << "                      Bienvenue sur la page de gestion des factures                               \n\n";
                        cout << "*******************        MENU        *******************************\n\n";
                        cout << "1. Creer une facture" << endl;
                        cout << "2. Afficher les factures" << endl;
                        cout << "3. Somme des prix de 2 factures" << endl;
                        cout << "4. afficher le map des projets" << endl;
                        cout << "5. Quitter" << endl;
                        cout << "Choix : ";
                        cin >> choixFacture;

                        switch (choixFacture) {
                            case 1:

                                {
                                    fichier3.open("factures.txt", ofstream::app);
                                    int idStartUp3;
                                    cout << "Entrez l'ID de la StartUp : ";
                                    cin >> idStartUp3;

                                    bool startUpTrouvee2 = false;
                                    for (int i = 0; i < liste.tailleTabStratUp(); ++i) {
                                        StartUp* startUp = liste.getStartUp(i);
                                        if (startUp->getId_startUp() == idStartUp3) {
                                            startUpTrouvee2 = true;
                                             startUp->creerFacture(fichier3);

                                            break;
                                        }
                                    }

                                    if (!startUpTrouvee2) {
                                        cout << "StartUp avec l'ID " << idStartUp3 << " non trouvée." << endl;
                                    }

                                    fichier3.close();
                                    break;
                                }
                            case 2:

                                {
                                    int idStartup;
                                    cout << "Entrez l'ID de la StartUp : ";
                                    cin >> idStartup;
                                    StartUp* startUp = nullptr;
                                    for (int i = 0; i < liste.tailleTabStratUp(); ++i) {
                                        if (liste.getStartUp(i)->getId_startUp() == idStartup) {
                                            startUp = liste.getStartUp(i);
                                            break;
                                        }
                                    }

                                    if (startUp) {
                                        startUp->afficherFacture();
                                    } else {
                                        cout << "StartUp avec l'ID " << idStartup << " non trouvée." << endl;
                                    }
                                    break;
                                }


                                case 3:
                                    {
                                        double res;
                                        cout<<"le prix total de la 1ere facture est:"<<f1.getPrixTotal()<<endl;
                                        cout<<"le prix total de la 2ere facture est:"<<f2.getPrixTotal()<<endl;
                                        res=f1+f2;
                                        cout<<"La somme des prix des factures est: "<<res<<endl;
                                        break;
                                    }
                            case 4:
                                {
                                     f3.afficherMap();

                                    break;
                                }



                            case 5:
                               cout << "Retour au menu principal" << endl;
                                retourMenu3 = true;
                                break;
                            default:
                                cout << "Choix invalide. Veuillez entrer un choix valide." << endl;
                                break;
                        }
                    }while (!retourMenu3);
                    retourMenu3 = false;
                    break;

                    case 3: // Organiser un événement
                        do
                        {

                            cout << "***********************************************************************\n\n\n";
                            cout << "                      Bienvenue sur la page d'organisation d'evenements                              \n\n";
                            cout << "*******************        MENU        *******************************\n\n";
                            cout << "1. Organiser une formation" << endl;
                            cout << "2. Organiser une conference" << endl;
                            cout << "3. Quitter" << endl;
                            cout << "Choix : ";

                            int choixEvenement;
                            cin >> choixEvenement;

                            switch (choixEvenement) {
                                case 1: // menu formation
                                {
                                   do {
                                        cout << "***********************************************************************\n\n\n";
                                        cout << "                      Bienvenue sur la page d'organisation de formations                              \n\n";
                                        cout << "*******************        MENU        *******************************\n\n";
                                        cout << "1. Creer une nouvelle formation" << endl;
                                        cout << "2. Ajouter Participant" << endl;
                                        cout << "3. Afficher la formation" << endl;
                                        cout << "4. Afficher les participants" << endl;
                                        cout << "5. Afficher les intervenants" << endl;
                                        cout << "6. Quitter" << endl;
                                        cout << "Choix : ";
                                        cin >> choix6;
                                        switch (choix6) {
                                            case 2://ajouter participant
                                                {

                                                    int idStartUp5;
                                                    do {
                                                        cout << "Entrez l'ID de la StartUp participant : ";
                                                        cin >> idStartUp5;
                                                        formationEvent->ajouterParticipant(idStartUp5,liste);
                                                        cout << "Voulez-vous ajouter un autre participant ? (oui/non) : ";
                                                        string reponse;
                                                        cin >> reponse;
                                                        if (reponse != "oui") break;
                                                    } while (true);
                                                    break;
                                                }
                                            case 1://creation d'une formation
                                                {try{

                                                formationEvent = new Formation();
                                                    //formationEvent->saisieEvent();
                                                    cin>>*formationEvent;

                                              } catch (const char* msg) {
                                                cout << "Erreur: " << msg << endl;
                                                }

                                                break;
                                                }

                                            case 3://afficher formation
                                                formationEvent->afficherEvent();
                                                break;
                                            case 4:
                                                formationEvent->afficherParticipant();
                                                break;
                                            case 5://Afficher les intervenants
                                                formationEvent->afficherIntervenant();
                                                break;
                                            case 6:
                                                testt = true;
                                            default:
                                                cout << "Choix invalide." << endl;
                                                break;
                                        }
                                    } while (!testt);
                                    break;
                                }
                                case 2: // Organiser une conférence
                                {
                                   do {
                                        cout << "***********************************************************************\n\n\n";
                                        cout << "                      Bienvenue sur la page d'organisation de conference                              \n\n";
                                        cout << "*******************        MENU        *******************************\n\n";
                                        cout << "1. Creer une nouvelle conference" << endl;
                                        cout << "2. Ajouter Participant" << endl;
                                        cout << "3. Afficher la conference" << endl;
                                        cout << "4. Afficher les participants" << endl;
                                        cout << "5. Afficher les conferencier" << endl;
                                        cout << "6. Quitter" << endl;
                                        cout << "Choix : ";
                                        cin >> choix5;
                                        switch (choix5) {
                                            case 2://ajouter participant
                                                {

                                                    int idStartUp5;
                                                    do {
                                                        cout << "Entrez l'ID de la StartUp participant : ";
                                                        cin >> idStartUp5;
                                                        ConferenceEvent->ajouterParticipant(idStartUp5,liste);
                                                        cout << "Voulez-vous ajouter un autre participant ? (oui/non) : ";
                                                        string reponse;
                                                        cin >> reponse;
                                                        if (reponse != "oui") break;
                                                    } while (true);
                                                    break;
                                                }
                                            case 1://creation d'une conference
                                                { try{

                                                    ConferenceEvent = new Conference();
                                                    //ConferenceEvent->saisieEvent();
                                                    cin>>*ConferenceEvent;

                                                }catch (const char* msg) {
                                                cout << "Erreur: " << msg << endl;
                                                }

                                                break;
                                                }

                                            case 3://afficher formation
                                                ConferenceEvent->afficherEvent();
                                                break;
                                            case 4:
                                                ConferenceEvent->afficherParticipant();
                                                break;
                                            case 5://Afficher les conferenciers
                                                ConferenceEvent->afficherConferencier();

                                                break;
                                            case 6:
                                                testt2 = true;
                                                break;
                                            default:
                                                cout << "Choix invalide." << endl;
                                                break;
                                        }
                                    } while (!testt2);
                                    break;
                                }
                                case 3:
                                    retourMenu5=true;
                                    break;
                                default:
                                    cout << "Choix invalide." << endl;
                                    break;
                            }

                        }while (!retourMenu5);
                    retourMenu5 = false;
                    break;


                case 5://allouer ressource
                  do
                    {

                        cout << "***********************************************************************\n\n\n";
                        cout << "                      Bienvenue sur la page d'allocation de ressources                               \n\n";
                        cout << "*******************        MENU        *******************************\n\n";
                        cout << "1. Allouer une ressource a une startUp" << endl;
                        cout << "2. Afficher les ressources d'une startUp" << endl;
                        cout << "3. Ajouter une ressource d'une startUp" << endl;
                        cout << "4. Supprimer une ressource d'une startUp" << endl;

                        cout << "5. Quitter" << endl;
                        cout << "Choix : ";
                        cin >> choixRessource;

                        switch (choixRessource) {
                            case 1://alouer des ressourse a une startUp donnee
                                {
                                   int idStartUp4;
                                    cout << "Entrez l'ID de la StartUp demandant une ressource : ";
                                    cin >> idStartUp4;

                                    bool startUpTrouvee2 = false;
                                    for (int i = 0; i < liste.tailleTabStratUp(); ++i) {
                                        StartUp* startUp = liste.getStartUp(i);
                                        if (startUp->getId_startUp() == idStartUp4) {
                                            startUpTrouvee2 = true;
                                            // alloue une ressource
                                            startUp->remplirTabRessource();
                                            break;
                                        }
                                    }

                                    if (!startUpTrouvee2) {
                                        cout << "StartUp avec l'ID " << idStartUp4 << " non trouvée." << endl;
                                    }
                                    break;
                                }
                            case 2://afficher les ressources d'une startUp

                                {
                                    int idStartUp4;
                                    cout << "Entrez l'ID de la StartUp demandant une ressource : ";
                                    cin >> idStartUp4;

                                    bool startUpTrouvee2 = false;
                                    for (int i = 0; i < liste.tailleTabStratUp(); ++i) {
                                        StartUp* startUp4 = liste.getStartUp(i);
                                        if (startUp4->getId_startUp() == idStartUp4) {
                                            startUpTrouvee2 = true;
                                        startUp4->afficherTabRessource();
                                            break;
                                            }
                                    }
                                    break;
                                    }


                                case 3: // Ajouter une ressource à une StartUp spécifique
                                    {
                                        int idStartUp;
                                        cout << "Entrez l'ID de la StartUp à laquelle vous souhaitez ajouter une ressource : ";
                                        cin >> idStartUp;

                                        StartUp* startUp = nullptr;
                                        for (int i = 0; i < liste.tailleTabStratUp(); ++i) {
                                            if (liste.getStartUp(i)->getId_startUp() == idStartUp) {
                                                startUp = liste.getStartUp(i);
                                                break;
                                            }
                                        }

                                        if (startUp) {

                                            do
                                            {
                                                int choixAjoutRessource;

                                                cout << "\nQuel type de ressource souhaitez-vous ajouter ?" << endl;
                                                cout << "1. Investisseur" << endl;
                                                cout << "2. Mentor" << endl;
                                                cout << "3. Ressource financière" << endl;
                                                cout << "4. Ressource matérielle" << endl;
                                                cout << "Entrez votre choix : ";
                                                cin >> choixAjoutRessource;

                                                switch (choixAjoutRessource)
                                                {
                                                    case 1: // Ajouter un investisseur
                                                    {

                                                        Investisseur* nouvelInvestisseur=new Investisseur();
                                                        cin>>*nouvelInvestisseur;
                                                        startUp->ajouterRessource(nouvelInvestisseur);
                                                        cout << "Investisseur ajoute avec succes a la StartUp." << endl;
                                                        break;
                                                    }
                                                    case 2: // Ajouter un mentor
                                                    {

                                                        Mentor* newMentor= new Mentor();
                                                        cin>>*newMentor;
                                                        startUp->ajouterRessource(newMentor);
                                                        cout << "Mentor ajoute avec succes a la StartUp." << endl;
                                                        break;
                                                    }
                                                    case 3: // Ajouter une ressource financière
                                                    {

                                                        Financiere* f=new Financiere();
                                                        cin>>*f;
                                                        startUp->ajouterRessource(f);
                                                        cout << "Ressource financiere ajoutee avec succes a la StartUp." << endl;
                                                        break;
                                                    }
                                                    case 4: // Ajouter une ressource matérielle
                                                    {

                                                        Materielle* m=new Materielle();
                                                        cin>>*m;
                                                        startUp->ajouterRessource(m);
                                                        cout << "Ressource materielle ajoutee avec succes a la StartUp." << endl;
                                                        break;
                                                    }
                                                    default:
                                                        cout << "Choix invalide. Veuillez entrer un choix valide." << endl;
                                                        break;
                                                }

                                                cout << "\nVoulez-vous ajouter une autre ressource ? (o/n) : ";
                                                cin >> rep;

                                            } while (rep == 'o' || rep == 'O');
                                        } else {
                                            cout << "StartUp avec l'ID " << idStartUp << " non trouvée." << endl;
                                        }

                                        break;
                                    }

                           case 4: // Supprimer une ressource d'une StartUp spécifique

                                    {
                                        cout << "Entrez l'ID de la StartUp a partir de laquelle vous souhaitez supprimer une ressource : ";
                                        cin >> idStartUp8;

                                        StartUp* startUp = nullptr;
                                        for (int i = 0; i < liste.tailleTabStratUp(); ++i) {
                                            if (liste.getStartUp(i)->getId_startUp() == idStartUp8) {
                                                startUp = liste.getStartUp(i);
                                                break;
                                            }
                                        }

                                        if (startUp) {
                                            int indiceRessource;
                                            cout << "Entrez l'indice de la ressource que vous souhaitez supprimer : ";
                                            cin >> indiceRessource;

                                            if (indiceRessource >= 0 && indiceRessource < startUp->tailleTabRessource()) {
                                                startUp->supprimerRessource(indiceRessource);
                                                cout << "Ressource supprimée avec succès de la StartUp." << endl;
                                            } else {
                                                cout << "Indice de ressource invalide. Veuillez entrer un indice valide." << endl;
                                            }
                                        } else {
                                            cout << "StartUp avec l'ID " << idStartUp8 << " non trouvée." << endl;
                                        }
                                        break;
                                    }

                            case 5:
                               cout << "Retour au menu principal" << endl;
                                retourMenu4 = true;
                                break;
                            default:
                                cout << "Choix invalide. Veuillez entrer un choix valide." << endl;
                                break;
                        }
                    }while (!retourMenu4);
                    retourMenu4 = false;
                    break;
                case 4:
                {
                    do
                    {
                        cout << "***********************************************************************\n\n\n";
                        cout << "                      Bienvenue sur la page de gestion de startUps                               \n\n";
                        cout << "*******************        MENU        *******************************\n\n";
                        cout << "1. Creation de fichier startUp" << endl;
                        cout << "2. Saisir startUps et ajout dans le fichier " << endl;
                        cout << "3. Ajouter une startUp dans le fichier " << endl; // remplir avec un autre objet startUp
                        cout << "4. Supprimer une startUp du fichier " << endl;
                        cout << "5. Afficher le fichier startUp " << endl;
                        cout << "6. Afficher map de startUp " << endl;
                        cout << "7. Quitter" << endl; // Option pour quitter
                        cout << "\nEntrez votre choix : ";
                        cin >> choix3;

                        switch (choix3)
                        {
                        case 1:
                            StartUp::creer(fichierS);
                            break;
                        case 2:

                          {try {
                                 int nombreStartUps;
                                cout << "Combien de StartUps souhaitez-vous saisir ? ";
                                cin >> nombreStartUps;

                                for (int i = 0; i < nombreStartUps; ++i) {
                                    StartUp* nouvelleStartUp = new StartUp; // Créer un nouvel objet StartUp à chaque fois
                                    //nouvelleStartUp->saisie_startup();
                                     cin>>*nouvelleStartUp;// Appeler la méthode de saisie sur le nouvel objet
                                    liste.ajouterStartUp(nouvelleStartUp); // Ajouter le nouvel objet à la liste
                                    liste.ajouterFinMap(nouvelleStartUp);///ajout au map
                                    nouvelleStartUp->remplir(fichierS);
                                }

                                 } catch (const char* message) {
                                    cerr << "Erreur : " << message << endl;
                                    }

                                break;

                            }
                        case 3:
                            {
                            do
                            {
                                StartUp s2;
                                //s2.saisie_startup();
                                cin>>s2;
                               /*hnee zedet fazet liste*/
                                liste.ajouterStartUp(&s2);

                                cout << "Ajout de la startUp dont l'id est: " << s2.getId_startUp() << endl;
                                ajouterStartUpsfichier(fichierS, s2);
                                do
                                {
                                    cout << "Voulez-vous encore ajouter une startup ? (1 pour oui, 0 pour non) : ";
                                    cin >> test2;
                                } while (test2 != 0 && test2 != 1);

                            } while (test2 == 1);

                            break;
                            }

                        case 4:

                                {
                                        cout << "donner l'id de la startUp a supprimer: ";
                                        cin >> id_supp;
                                        cout << "Suppression de la startUp dont l'id est: " << id_supp << endl;
                                        StartUp::supprimerStratUpsfichier(fichierS, id_supp);
                                        break;
                                }
                        case 5:
                            {
                                  fichier.open("startUps.txt");
                                StartUp::afficherFichier(fichier);
                                break;
                            }


                        case 6:///affichage du map
                            {
                                 liste.afficherMap();
                                break;
                            }
                        case 7:
                            {
                                 retourMenu = true;
                                break;
                            }


                        default:
                            cout << "Choix invalide. Veuillez reessayer.\n";
                            break;
                        }

                    } while (!retourMenu);

                    retourMenu = false;
                    break;}
                }
            }
        }
        else
        {
            cout << "erreur";
        }
        break;
    case 2:
        cout << "Veuillez entrer les donnees suivantes :" << endl;
        cout << "NOM UTILISATEUR :";
        cin >> user;
        cout << "MOT DE PASSE :";
        cin >> pass;

        input_employe.open("employes.txt");
        while (input_employe >> u >> p)
        {
            if (u == user && p == pass)
            {
                test = 1;
                system("cls");
                break;
            }
        }
        input_employe.close();

        if (test == 1)
        {
            cout << "\nBienvenue " << user << "\n<AUTHENTIFICATION REUSSIE>\n";
           cin.get();
           while (menuEmp)
           {

            cout << "***********************************************************************\n\n\n";
            cout << "                      Bienvenue sur la page de l'employe                               \n\n";
            cout << "*******************        MENU        *******************************\n\n";
            cout << "1. Gerer StratUps" << endl;
            cout << "2. Allouer ressources " << endl;
            cout << "\nEntrez votre choix :";

            cin>>choixEmp;

            switch(choixEmp){

            case 1:

                 {
                    do
                    {
                        cout << "***********************************************************************\n\n\n";
                        cout << "                      Bienvenue sur la page de gestion de startUps                               \n\n";
                        cout << "*******************        MENU        *******************************\n\n";
                        cout << "1. Creation de fichier startUp" << endl;
                        cout << "2. Saisir startUps et ajout dans le fichier " << endl;
                        cout << "3. Ajouter une startUp dans le fichier " << endl; // remplir avec un autre objet startUp
                        cout << "4. Supprimer une startUp du fichier " << endl;
                        cout << "5. Afficher le fichier startUp " << endl;
                        cout << "6. Afficher map de startUp " << endl;
                        cout << "7. Quitter" << endl; // Option pour quitter
                        cout << "\nEntrez votre choix : ";
                        cin >> choix3;

                        switch (choix3)
                        {
                        case 1:
                            StartUp::creer(fichierS);
                            break;
                        case 2:

                          {
                              try {
                                 int nombreStartUps;
                                cout << "Combien de StartUps souhaitez-vous saisir ? ";
                                cin >> nombreStartUps;

                                for (int i = 0; i < nombreStartUps; ++i) {
                                    StartUp* nouvelleStartUp = new StartUp; // Créer un nouvel objet StartUp à chaque fois
                                    //nouvelleStartUp->saisie_startup();
                                     cin>>*nouvelleStartUp;// Appeler la méthode de saisie sur le nouvel objet
                                    liste.ajouterStartUp(nouvelleStartUp); // Ajouter le nouvel objet à la liste
                                    liste.ajouterFinMap(nouvelleStartUp);///ajout au map
                                    nouvelleStartUp->remplir(fichierS);
                                }

                                 } catch (const char* message) {
                                    cerr << "Erreur : " << message << endl;
                                    }

                                break;

                            }
                        case 3:
                            {
                            do
                            {
                                StartUp s2;
                                //s2.saisie_startup();
                                cin>>s2;
                               /*hnee zedet fazet liste*/
                                liste.ajouterStartUp(&s2);

                                cout << "Ajout de la startUp dont l'id est: " << s2.getId_startUp() << endl;
                                ajouterStartUpsfichier(fichierS, s2);
                                do
                                {
                                    cout << "Voulez-vous encore ajouter une startup ? (1 pour oui, 0 pour non) : ";
                                    cin >> test2;
                                } while (test2 != 0 && test2 != 1);

                            } while (test2 == 1);

                            break;
                            }

                        case 4:

                                {
                                        cout << "donner l'id de la startUp a supprimer: ";
                                        cin >> id_supp;
                                        cout << "Suppression de la startUp dont l'id est: " << id_supp << endl;
                                        StartUp::supprimerStratUpsfichier(fichierS, id_supp);
                                        break;
                                }
                        case 5:
                            {
                                  fichier.open("startUps.txt");
                                StartUp::afficherFichier(fichier);
                                break;
                            }


                        case 6:///affichage du map
                            {
                                 liste.afficherMap();


                                break;
                            }
                        case 7:
                            {
                                 retourMenu = true;
                                break;
                            }


                        default:
                            cout << "Choix invalide. Veuillez reessayer.\n";
                            break;
                        }

                    } while (!retourMenu);

                    retourMenu = false;
                    break;



                    }
            case 2 :

            {

                 do
                    {

                        cout << "***********************************************************************\n\n\n";
                        cout << "                      Bienvenue sur la page d'allocation de ressources                               \n\n";
                        cout << "*******************        MENU        *******************************\n\n";
                        cout << "1. Allouer une ressource a une startUp" << endl;
                        cout << "2. Afficher les ressources d'une startUp" << endl;
                        cout << "3. Ajouter une ressource d'une startUp" << endl;
                        cout << "4. Supprimer une ressource d'une startUp" << endl;

                        cout << "5. Quitter" << endl;
                        cout << "Choix : ";
                        cin >> choixRessource;

                        switch (choixRessource) {
                            case 1://alouer des ressourse a une startUp donnee
                                {
                                   int idStartUp4;
                                    cout << "Entrez l'ID de la StartUp demandant une ressource : ";
                                    cin >> idStartUp4;

                                    bool startUpTrouvee2 = false;
                                    for (int i = 0; i < liste.tailleTabStratUp(); ++i) {
                                        StartUp* startUp = liste.getStartUp(i);
                                        if (startUp->getId_startUp() == idStartUp4) {
                                            startUpTrouvee2 = true;
                                            // alloue une ressource
                                            startUp->remplirTabRessource();
                                            break;
                                        }
                                    }

                                    if (!startUpTrouvee2) {
                                        cout << "StartUp avec l'ID " << idStartUp4 << " non trouvée." << endl;
                                    }
                                    break;
                                }
                            case 2://afficher les ressources d'une startUp

                                {
                                    int idStartUp4;
                                    cout << "Entrez l'ID de la StartUp demandant une ressource : ";
                                    cin >> idStartUp4;

                                    bool startUpTrouvee2 = false;
                                    for (int i = 0; i < liste.tailleTabStratUp(); ++i) {
                                        StartUp* startUp4 = liste.getStartUp(i);
                                        if (startUp4->getId_startUp() == idStartUp4) {
                                            startUpTrouvee2 = true;
                                        startUp4->afficherTabRessource();
                                            break;
                                            }
                                    }
                                    break;
                                    }


                                case 3: // Ajouter une ressource à une StartUp spécifique
                                    {
                                        int idStartUp;
                                        cout << "Entrez l'ID de la StartUp à laquelle vous souhaitez ajouter une ressource : ";
                                        cin >> idStartUp;

                                        StartUp* startUp = nullptr;
                                        for (int i = 0; i < liste.tailleTabStratUp(); ++i) {
                                            if (liste.getStartUp(i)->getId_startUp() == idStartUp) {
                                                startUp = liste.getStartUp(i);
                                                break;
                                            }
                                        }

                                        if (startUp) {

                                            do
                                            {
                                                int choixAjoutRessource;

                                                cout << "\nQuel type de ressource souhaitez-vous ajouter ?" << endl;
                                                cout << "1. Investisseur" << endl;
                                                cout << "2. Mentor" << endl;
                                                cout << "3. Ressource financière" << endl;
                                                cout << "4. Ressource matérielle" << endl;
                                                cout << "Entrez votre choix : ";
                                                cin >> choixAjoutRessource;

                                                switch (choixAjoutRessource)
                                                {
                                                    case 1: // Ajouter un investisseur
                                                    {

                                                        Investisseur* nouvelInvestisseur=new Investisseur();
                                                        cin>>*nouvelInvestisseur;
                                                        startUp->ajouterRessource(nouvelInvestisseur);
                                                        cout << "Investisseur ajoute avec succes a la StartUp." << endl;
                                                        break;
                                                    }
                                                    case 2: // Ajouter un mentor
                                                    {

                                                        Mentor* newMentor= new Mentor();
                                                        cin>>*newMentor;
                                                        startUp->ajouterRessource(newMentor);
                                                        cout << "Mentor ajoute avec succes a la StartUp." << endl;
                                                        break;
                                                    }
                                                    case 3: // Ajouter une ressource financière
                                                    {

                                                        Financiere* f=new Financiere();
                                                        cin>>*f;
                                                        startUp->ajouterRessource(f);
                                                        cout << "Ressource financiere ajoutee avec succes a la StartUp." << endl;
                                                        break;
                                                    }
                                                    case 4: // Ajouter une ressource matérielle
                                                    {

                                                        Materielle* m=new Materielle();
                                                        cin>>*m;
                                                        startUp->ajouterRessource(m);
                                                        cout << "Ressource materielle ajoutee avec succes a la StartUp." << endl;
                                                        break;
                                                    }
                                                    default:
                                                        cout << "Choix invalide. Veuillez entrer un choix valide." << endl;
                                                        break;
                                                }

                                                cout << "\nVoulez-vous ajouter une autre ressource ? (o/n) : ";
                                                cin >> rep;

                                            } while (rep == 'o' || rep == 'O');
                                        } else {
                                            cout << "StartUp avec l'ID " << idStartUp << " non trouvée." << endl;
                                        }

                                        break;
                                    }

                           case 4: // Supprimer une ressource d'une StartUp spécifique

                                    {
                                        cout << "Entrez l'ID de la StartUp a partir de laquelle vous souhaitez supprimer une ressource : ";
                                        cin >> idStartUp8;

                                        StartUp* startUp = nullptr;
                                        for (int i = 0; i < liste.tailleTabStratUp(); ++i) {
                                            if (liste.getStartUp(i)->getId_startUp() == idStartUp8) {
                                                startUp = liste.getStartUp(i);
                                                break;
                                            }
                                        }

                                        if (startUp) {
                                            int indiceRessource;
                                            cout << "Entrez l'indice de la ressource que vous souhaitez supprimer : ";
                                            cin >> indiceRessource;

                                            if (indiceRessource >= 0 && indiceRessource < startUp->tailleTabRessource()) {
                                                startUp->supprimerRessource(indiceRessource);
                                                cout << "Ressource supprimée avec succès de la StartUp." << endl;
                                            } else {
                                                cout << "Indice de ressource invalide. Veuillez entrer un indice valide." << endl;
                                            }
                                        } else {
                                            cout << "StartUp avec l'ID " << idStartUp8 << " non trouvée." << endl;
                                        }
                                        break;
                                    }

                            case 5:
                               cout << "Retour au menu principal" << endl;
                                retourMenu4 = true;
                                break;
                            default:
                                cout << "Choix invalide. Veuillez entrer un choix valide." << endl;
                                break;
                        }
                    }while (!retourMenu4);
                    retourMenu4 = false;
                    break;



                    }
            }

        }

        }
        else
        {
            cout << "\nERREUR DE CONNEXION\nVeuillez vérifier votre nom d'utilisateur et votre mot de passe\n";
        }
        break;

    default:
        cout << "Choix invalide. Veuillez réessayer.\n";
        break;
    }
}

void enregistrer()
{
    int choix;
    string enr_admin, enr_adm_pass, enr_user, enr_pass;
    system("cls");
    cout << "***********************************************************************\n\n\n";
    cout << "                      Bienvenue sur la page d'enregistrement                               \n\n";
    cout << "*******************        MENU        *******************************\n\n";
    cout << "1. Enregistrer en tant qu'administrateur:" << endl;
    cout << "2. Enregistrer en tant qu'employe:" << endl;
    cout << "\nEntrez votre choix :";
    cin >> choix;
    cout << endl;

    ofstream enregistrement_admin;
    ofstream enregistrement_employe;

    switch (choix)
    {
    case 1:
        cout << "Entrer le nom d'administrateur :";
        cin >> enr_admin;
        cout << "\nEntrer le mot de passe :";
        cin >> enr_adm_pass;

        enregistrement_admin.open("admin.txt", ios::app);
        enregistrement_admin << enr_admin << ' ' << enr_adm_pass << endl;
        enregistrement_admin.close();
        system("cls");
        cout << "\nEnregistrement reussi\n";
        break;

    case 2:
        cout << "Entrer le nom d'utilisateur :";
        cin >> enr_user;
        cout << "\nEntrer le mot de passe :";
        cin >> enr_pass;

        enregistrement_employe.open("employes.txt", ios::app);
        enregistrement_employe << enr_user << ' ' << enr_pass << endl;
        enregistrement_employe.close();
        system("cls");
        cout << "\nEnregistrement reussi\n";
        break;

    default:
        cout << "Choix invalide. Veuillez reessayer.\n";
        break;
    }
}

void ajouterStartUpsfichier(fstream &f, StartUp s)
{
    ofstream fichier("startUps.txt", ios::app);
    if (fichier.is_open())
    {
        fichier << s.id_startUp << ' ' << s.nom_stratUp << ' ' << s.nom_fondateur << ' ' << s.domaine_activite << ' ' << s.budget << ' ' << s.anneeCreation << endl;
        fichier.close();
        cout << "Donnees remplies avec succes " << endl;
    }
    else
    {
        cerr << "Impossible d'ouvrir le fichier : " << endl;
    }
}









