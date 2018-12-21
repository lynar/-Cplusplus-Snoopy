#include "Ball.h"

Ball::Ball() ///constructeur
{
}

Ball::~Ball() ///destructeur
{
    //dtor
}
void Ball::deplacementBall() ///fonction qui gere le deplacemment de la balle
{

    m_coordX=m_coordX+m_depx;///ajout des coordonnées de déplacement au coordonnées de la balle
    m_coordY=m_coordY+m_depy;

}

int Ball::getdepx() const ///getter coordonnées déplacement
{
    return m_depx; ///pour x
}

int Ball::getdepy() const ///getter coordonnées déplacement
{
    return m_depy; ///pour y
}

///FONCTIONS D'INVERSION DES COORDONNEES POUR LES COLLISIONS
//sur X
void Ball::inverseX()
{
    m_depx = -m_depx;
}
//sur Y
void Ball::inverseY()
{
    m_depy = -m_depy;
}

///getters des attributs de la classe ball
int Ball::getBallPosx() const
{
    return m_coordX;
}

int Ball::getBallPosy() const
{
    return m_coordY;
}

///affichage de la balle
void Ball::Affichage(Console* pConsole)
{
    pConsole->gotoLigCol(m_coordY,m_coordX);
    pConsole->setColor(COLOR_RED);
    std::cout<<"B";

}

///suppression de la balle
void Ball::deleteAffichage(Console* pConsole)
{
    pConsole->gotoLigCol(m_coordY,m_coordX);
    pConsole->setColor(COLOR_RED);
    std::cout<<" ";

}

///setter des coordonnées de la classe ball
void Ball::setBall(int _coordX, int _coordY)
{
    int temp;

    m_coordX=_coordX;
    m_coordY=_coordY;

    temp=rand()%2; ///donne une valeur alléatoire entre un et deux pour déterminer le sens du déplacement des coordonnées
    ///POUR X
    if(temp==0) m_depx=-1;
    if(temp==1) m_depx=1;
    temp=rand()%2; ///donne une valeur alléatoire entre un et deux pour déterminer le sens du déplacement des coordonnées
    ///POUR Y
    if(temp==0) m_depy=-1;
    if(temp==1) m_depy=1;
}



