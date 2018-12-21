#ifndef BLOCPIEGE_H_INCLUDED
#define BLOCPIEGE_H_INCLUDED

#include "object.h"

class BlocPiege : public Object ///classe bloccassable qui herite de object
{
private:    //attributs
    bool m_vivant;

public:
    //constructeur destructeur
    BlocPiege();
    ~BlocPiege();

    //accesseurs
    ///getters
    int getBlocPieX() const;
    int getBlocPieY() const;
    ///setters
    void setBlocPie(int _coordX, int _coordY);
};


#endif // BLOCPIEGE_H_INCLUDED
