#include "BlocPoussable.h"

///constructor
BlocPoussable::BlocPoussable()
{
}
///destructor
BlocPoussable::~BlocPoussable()
{
}

///METHODES
///fonction dde d�placement du bloc
void BlocPoussable::deplacerBloc(char dep)
{

    switch(dep) ///boucle switch qui permet de d�terminer dans quel sens va etre pouss� le bloc
    {
    case '8':
    case 'z':
        m_coordY--;///si on lui demande de pousser vers le haut
        break;

    case '2':
    case 's':
        m_coordY++;///si on lui demande de pousser vers le bas
        break;

    case '4':
    case 'q':
        m_coordX--;///si on lui demande de pousser vers la gauche
        break;

    case '6':
    case 'd':
        m_coordX++;///si on lui demande de pousser vers la droite
        break;
    }

}

///fonction de suppression du bloc sur l'ancienne case ou il �tait
void BlocPoussable::deleteAffichage(Console* pConsole,int Y,int X) ///supprimer le bloc pouss�
{
    pConsole->gotoLigCol(Y,X);
    std::cout<<" ";

}

///fonction qui fait afficher le bloc sur la nouvelle case vers laquelle il a �t� pouss�
void BlocPoussable::Affichage(Console* pConsole,int Y,int X)///affiche le bloc pouss� � sa nouvelle place
{
    pConsole->gotoLigCol(Y,X);
    pConsole->setColor(COLOR_GREEN);
    std::cout<<"P";

}


///getter
int BlocPoussable::getBlocPouX() const
{
    return m_coordX; ///coordonn�e X
}

int BlocPoussable::getBlocPouY()const
{
    return m_coordY; ///coordonn�e Y
}

///setter
void BlocPoussable::setBlocPou(int _coordX, int _coordY)
{
    m_coordX=_coordY;
    m_coordY=_coordY;
}
