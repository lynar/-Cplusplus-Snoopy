#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include "console.h"

class Object
{
protected: ///peut etre modifié dans les classes héritières
    int m_coordX;               // coordonnées en X
    int m_coordY;

public:
    //constructeur destructeur
    Object();
    Object(int coordX, int coordY);
    ~Object();
    //methods

    //accesseurs
    ///getters
    int getcoordX() const;
    int getcoordY() const;
    ///setters
    void setCoordX(int _coordX);
    void setCoordY(int _coordY);
};

#endif // OBJECT_H_INCLUDED
