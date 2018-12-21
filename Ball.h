#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED

#include "object.h"

class Ball : public Object ///classe Ball qui hérite de la classe object
{
public:
    Ball();///constructeur
    ~Ball();///destructeur

    void deplacementBall();///methode qui controle le mouvement de la balle
///methode d'inversion des coordonnées
    void inverseX();
    void inverseY();
    ///methode d'affichage et de suppression de la balle
    void Affichage(Console* pConsole);
    void deleteAffichage(Console* pConsole);

///getter et setter
    int getBallPosx() const;
    int getBallPosy() const;
    int getdepx() const;
    int getdepy() const;
    void setBall(int _coordX, int _coordY);

    ///attribut de l'objet en privé
private:
    int m_depx;
    int m_depy;


};

#endif // BALL_H_INCLUDED
