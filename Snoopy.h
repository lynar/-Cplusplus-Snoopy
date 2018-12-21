#ifndef SNOOPY_H_INCLUDED
#define SNOOPY_H_INCLUDED

#include "object.h"

class Snoopy : public Object ///classe snoopy qui herite de la classe objet
{
public:
    Snoopy(); ///constructeur
    ~Snoopy(); ///destructeur

    void deplacerSnoopy(char dep);

///GETTER
    int getSnoopyPosx() const;
    int getSnoopyPosy() const;
    int getnbOisRecup() const;
///SETTER
    void setnbOisRecup();
    void setSnoopy(int _coordX, int _coordY);

///methode qui affiche ou supprime snoopy
    void Affichage(Console* pConsole);
    void deleteAffichage(Console* pConsole);

private: ///attribut de la classe
    int m_nbOisRecup;

};

#endif // SNOOPY_H_INCLUDED
