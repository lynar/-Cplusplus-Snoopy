#include "Object.h"

///constructor
Object::Object() : m_coordX(0), m_coordY(0)
{
}
///constructeur surchargé
Object::Object(int coordX, int coordY) : m_coordX(coordX), m_coordY(coordY)
{
}
///destructor
Object::~Object()
{
}

//accesseurs
///on récupère la coordonnée en X
int Object::getcoordX() const
{
    return m_coordX;
}
///on récupère la coordonnée en Y
int Object::getcoordY() const
{
    return m_coordY;
}

///on modifie la coordonnée en X
void Object::setCoordX(int _coordX)
{
    m_coordX=_coordX;
}
///on modifie la coordonnée en Y
void Object::setCoordY(int _coordY)
{
    m_coordY=_coordY;
}
