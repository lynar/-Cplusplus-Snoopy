#include "BlocPiege.h"

///constructor
BlocPiege::BlocPiege()
{
}
///destructor
BlocPiege::~BlocPiege()
{
}

///getter
int BlocPiege::getBlocPieX() const
{
    return m_coordX;///pour les coordonnées de X
}

int BlocPiege::getBlocPieY() const
{
    return m_coordY;///pour les coordonnées de Y
}

///setter
void BlocPiege::setBlocPie(int _coordX, int _coordY)
{
    m_coordX=_coordX;
    m_coordY=_coordY;
}

