#include "BlocCassable.h"

///constructor
BlocCassable::BlocCassable()
{
}

///destructor
BlocCassable::~BlocCassable()
{
}

///getter des attributs de la classe
int BlocCassable::getBlocCasX() const
{
    return m_coordX; ///pour la coordonnée sur x
}

int BlocCassable::getBlocCasY() const
{
    return m_coordY;///pour la coordonnée sur y
}

///setter
void BlocCassable::setBlocCas(int _coordX, int _coordY)
{
    m_coordX=_coordX;
    m_coordY=_coordY;
}


///methode
///supprime les blocs cassés
void BlocCassable::deleteAffichage(Console* pConsole,int Y,int X)
{
    pConsole->gotoLigCol(Y,X);
    pConsole->setColor(COLOR_GREEN);
    std::cout<<" ";

}
