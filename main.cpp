#include <iostream>
#include <fstream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <string>
using namespace std;

string mixable(string word) // Source corrected from: https://openclassrooms.com/courses/programmez-avec-le-langage-c/tp-le-mot-mystere
{
    string mix;
    int position(0);
    while (word.size() != 0)
    {
        position = rand() % word.size();
        mix += word[position];
        word.erase(position, 1);
    }
    return mix;
}

int main()
{
    srand (time(NULL)); /* initialize random seed: */
    cout << "TuxBot est un jeu pour enfants de : " << endl;
    cout << "http://appli-etna.ac-nantes.fr:8080/ia53/tice/ressources/tuxbot/index.php" << endl;
    bool inputOk = true;
    int taille = 0;
    string inputString = "";
    const int MAXINTRUCTIONS = 24;
    do
    {
        cout << "Taille ? (8, 10, 16 : c\'est obligatoire pour TuxBot !)  ";
        inputOk = true; // Pour autre demande éventuelle.
        try
        {
            getline(cin, inputString); // Pour éviter des bugs de non nombre.
            taille = stoi(inputString);  // cin.
        }
        catch (const std::invalid_argument& e)
        {
            cerr << "Un nombre, svp ! (8, 10, 16 : c\'est obligatoire pour TuxBot !) " << endl;
            inputOk = false;
        }
        if ((taille!=8) && (taille!=10) && (taille!=16) )
        {
            inputOk = false;
        }
    }
    while (inputOk == false);
    int tailleX = taille;
    int tailleY = taille;
    int tableau[tailleX][tailleY];
    // Position aléatoire de Tux :
    // TODO:
    int XTuxInit = rand()%tailleX;
    int YTuxInit = rand()%tailleY;
    int orientTuxInit = rand()%4 + 1; // E = 1, N = 2, W = 3, S = 4; // Trigo. // 0 = vide.
    for (int a=0; a<tailleX; a++)
    {
        for (int b=0; b<tailleY; b++)
        {
            if ((a==XTuxInit) && (b==YTuxInit))
            {
                tableau[a][b] =  orientTuxInit;
            }
            else
            {
                tableau[a][b] =  0;
            }
        }
    }

    for (int instuction = 1; instuction < MAXINTRUCTIONS + 1; instuction++)
    {

// Tentative de manger :

// Tentative d'avancer :

// Tentative de tourner :





    }

// Fichier non plein ASCII :
// On affiche juste :
    for (int a=0; a<tailleX; a++)
    {
        for (int b=0; b<tailleY; b++)
        {
            cout << tableau[a][b] << " " ;
        }
        cout << endl;
    }
    return 0;
}
