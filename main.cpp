#include <iostream>
#include "livre.h"
#include "auteur.h"
#include "lecteur.h"
#include "emprunt.h"
#include "library.h"
using namespace std;

int main()
{
    int x;
    cout << "Bienvenue dans la bibliotheque!" << endl;
    cout << endl;
    cout << "Choisissez une action: " << endl;
    cout << "1: Ajouter un livre        2: Ajouter un lecteur" << endl;
    cout << "3: Still developing        4: Still developing" << endl;
    cin >>  x;
    Library biblio;

    switch(x)
    {
    case 1:
        biblio.addLivre();
        break;
    case 2:
        biblio.addLecteur();
        break;
    case 3:
        cout << "Still developing" << endl;
        break;
    case 4:
        cout << "Still developing" << endl;
        break;
    }

    /*Emprunt cpp("007");
    Lecteur Raif("Sguiar","Raif",001);
    if(cpp.emprunterLivre("007"))
    {
        Raif.addIsbn("007");
    }
    else
    {
        cout << "Le livre est deja emprunte" << endl;
    }
    Raif.afficherIsbns();
    */
}
