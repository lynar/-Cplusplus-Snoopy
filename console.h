#ifndef CONSOLE_H_INCLUDED
#define CONSOLE_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <time.h>   ///bibliothéque pour la fonction de temps
#include <windows.h>
#include <cfloat>    /// permet d'avoir FLT_MAX
#include <climits>   /// permet d'avoir INT_MAX
#include <limits>
#include <conio.h>
#include <fstream>  /// Librarie pour pouvoir utiliser ifstream/ofstream
#include <string>   ///lbibliothéque pour les string
#include <vector>   ///bibliothéque des vecteurs pour la matrice

enum Color ///code couleur
{
    COLOR_BLACK = 0,
    COLOR_WHITE = 1,
    COLOR_RED = 2,
    COLOR_GREEN = 3,
    COLOR_BLUE = 4,
    COLOR_YELLOW = 5,
    COLOR_PURPLE = 6,
    COLOR_DEFAULT = 7,
    COLOR_TURQUOISE=11,
    COLOR_PINK=13,// gris couleur de base de la console
};

class Console
{
private:
    // Empecher la création
    Console();
    ~Console();

    // Empecher la copie d'objet...
    Console& operator= (const Console&)
    {
        return *this;
    }
    Console (const Console&) {}

    // Attributs
    static Console* m_instance;

    // Méthodes privées
    void _setColor(int front, int back);
public:
    // Méthodes statiques (publiques)
    static Console* getInstance();
    static void deleteInstance();

    // Méthodes publiques
    void gotoLigCol(int lig, int col);
    bool isKeyboardPressed();
    int getInputKey();
    void setColor(Color col);
};

#endif // CONSOLE_H_INCLUDED
