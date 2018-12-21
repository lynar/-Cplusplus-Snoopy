#include "Oiseaux.h"

///constructor
Oiseaux::Oiseaux()
{
}
///constructeur surcharg�
Oiseaux::Oiseaux(int _coordX,int _coordY) : Object(_coordX, _coordY)
{
}

///destructor
Oiseaux::~Oiseaux()
{
}

///getter
int Oiseaux::getOiseauxX() const
{
    return m_coordX; ///pour recup�rer X
}

int Oiseaux::getOiseauxY() const
{
    return m_coordY;///pour recup�rer Y
}

///setter
void Oiseaux::setOiseaux(int _coordX, int _coordY)
{
    m_coordX=_coordX;
    m_coordY=_coordY;
}

