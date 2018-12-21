#ifndef NIVEAU_H_INCLUDED
#define NIVEAU_H_INCLUDED

#include "console.h"
#include "object.h"
#include "Oiseaux.h"
#include "BlocPoussable.h"
#include "BlocCassable.h"
#include "BlocPiege.h"
#include "Snoopy.h"
#include "Ball.h"

class Niveau
{
private: ///attributs
    std::vector < std::vector <char> >  matrice; ///création du vecteur matrice
    ///variable global de type classe
    Snoopy snoopy;
    Ball ball;
    ///attributs
    int m_vie;
    int m_niveau;
    int m_score;

public:
    Niveau(); ///constructeur
    ~Niveau(); ///destructeur

    void LoadFromFile(const std::string& path); ///methodes de lecture de fichier pour affichage des objets
    void afficherMatrice(Console* pConsole); ///methode d'affichage de la matrice grace à la methode loadfromfile

    ///getter
    int getVie() const;
    int getNiveau() const;
    int getScore() const;
    Snoopy getSnoopie() const;
    Ball getBall() const;
    char getmatrice(int x, int y) const;
    ///setter
    void setVie(int nb);
    void setNiveau(int level);
    void setCase(char lettre, int _posx, int _posy);
    void setmatrice(int x, int y, char value);



};

#endif // NIVEAU_H_INCLUDED
