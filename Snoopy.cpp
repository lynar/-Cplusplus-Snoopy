#include "Snoopy.h"

///contructeur
Snoopy::Snoopy()
{
}

///destructeur
Snoopy::~Snoopy()
{
}

///methodes
void Snoopy::deplacerSnoopy(char dep)
{

    switch(dep) ///deplacement de snoopy en fonction de la touche
    {
    case '8':
    case 'z':
        m_coordY--; ///monte
        break;

    case '2':
    case 's':
        m_coordY++;///descend
        break;

    case '4':
    case 'q':
        m_coordX--;///gauche
        break;

    case '6':
    case 'd':
        m_coordX++;///droite
        break;
    }

}

///supprimer snoopy
void Snoopy::deleteAffichage(Console* pConsole)
{
    pConsole->gotoLigCol(m_coordY,m_coordX);
    pConsole->setColor(COLOR_BLACK);
    std::cout<<" ";///suppression en remplaçant par du blanc

}

///affichage de snoopy
void Snoopy::Affichage(Console* pConsole)
{
    pConsole->gotoLigCol(m_coordY,m_coordX);
    pConsole->setColor(COLOR_BLUE);
    std::cout<<"S";

}

///getter
int Snoopy::getSnoopyPosx() const
{
    return m_coordX;
}

int Snoopy::getSnoopyPosy() const
{
    return m_coordY;
}

int Snoopy::getnbOisRecup() const
{
    return m_nbOisRecup;
}

///setter
void Snoopy::setnbOisRecup()
{
    m_nbOisRecup++;
}

void Snoopy::setSnoopy(int _coordX, int _coordY)
{
    m_coordX=_coordX;
    m_coordY=_coordY;
    m_nbOisRecup=0;///initialisation du nombre d'oiseaux
}

