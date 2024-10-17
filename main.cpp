#include <iostream>
#include "login.cpp"
#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>

using namespace std;

int main()
{
      int choix;
        cout<<"***********************************************************************\n\n\n";
        cout<<"                      Bienvenue sur la page d'acceuil                              \n\n";
        cout<<"*******************        MENU        *******************************\n\n";
        cout<<"1.SE CONNECTER"<<endl;
        cout<<"2.ENREGISTRER"<<endl;
        cout<<"3.SORTIE"<<endl;
        cout<<"\nEntrer votre choix :";
        cin>>choix;
        cout<<endl;
         switch(choix)
        {
                case 1:
                        login();
                        break;
                case 2:
                        enregistrer();
                        main();
                        break;
                case 3:
                        system("cls");
                        main();
                default:
                        system("cls");
                        cout<<"You've made a mistake , Try again..\n"<<endl;
                    main();
        }

    return 0;
}
