#ifndef BLOCCASSABLE_H_INCLUDED
#define BLOCCASSABLE_H_INCLUDED

#include "object.h"

class BlocCassable : public Object ///classe bloccassable qui herite de object
{

public:
    //constructeur destructeur
    BlocCassable();
    ~BlocCassable();
    //accesseurs
    ///getters
    int getBlocCasX() const;
    int getBlocCasY() const;
    ///setters
    void setBlocCas(int _coordX, int _coordY);
    void deleteAffichage(Console* pConsole,int Y,int X);
};

#endif // BLOCCASSABLE_H_INCLUDED
