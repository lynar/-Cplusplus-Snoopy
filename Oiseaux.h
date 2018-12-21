#ifndef OISEAUX_H_INCLUDED
#define OISEAUX_H_INCLUDED

#include "object.h"

class Oiseaux : public Object
{
private:
     //attributs
protected: ///peut etre modifi� dans les classes h�riti�res

public:
    //constructeur destructeur
    Oiseaux();
    Oiseaux(int _coordX,int _coordY);
    ~Oiseaux();

    //accesseurs
    ///getters
    int getOiseauxX() const;
    int getOiseauxY() const;

    ///setter
    void setOiseaux(int _coordX, int _coordY);

};

#endif // OISEAUX_H_INCLUDED
