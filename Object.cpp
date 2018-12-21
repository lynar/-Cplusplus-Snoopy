#include "Object.h"

///constructor
Object::Object() : m_coordX(0), m_coordY(0)
{
}
///constructeur surcharg�
Object::Object(int coordX, int coordY) : m_coordX(coordX), m_coordY(coordY)
{
}
///destructor
Object::~Object()
{
}

//accesseurs
///on r�cup�re la coordonn�e en X
int Object::getcoordX() const
{
    return m_coordX;
}
///on r�cup�re la coordonn�e en Y
int Object::getcoordY() const
{
    return m_coordY;
}

///on modifie la coordonn�e en X
void Object::setCoordX(int _coordX)
{
    m_coordX=_coordX;
}
///on modifie la coordonn�e en Y
void Object::setCoordY(int _coordY)
{
    m_coordY=_coordY;
}
