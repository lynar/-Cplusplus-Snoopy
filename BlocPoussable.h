#ifndef BLOCPOUSSABLE_H_INCLUDED
#define BLOCPOUSSABLE_H_INCLUDED

#include "object.h"

class BlocPoussable : public Object ///classe blocpoussable qui herite de object
{
private:    //attributs
    bool m_vivant;

public:
    //constructeur destructeur
    BlocPoussable();
    ~BlocPoussable();

    void deplacerBloc(char dep);
    //methods
    void afficherBloc3(int x,int y);

    void Affichage(Console* pConsole,int Y,int X);
    void deleteAffichage(Console* pConsole,int Y,int X);

    //accesseurs
    ///getters
    int getBlocPouX() const;
    int getBlocPouY() const;
    ///setters
    void setBlocPou(int _coordX, int _coordY);
};

#endif // BLOCPOUSSABLE_H_INCLUDED
