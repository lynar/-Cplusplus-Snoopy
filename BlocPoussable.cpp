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
///fonction dde déplacement du bloc
void BlocPoussable::deplacerBloc(char dep)
{

    switch(dep) ///boucle switch qui permet de déterminer dans quel sens va etre poussé le bloc
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

///fonction de suppression du bloc sur l'ancienne case ou il était
void BlocPoussable::deleteAffichage(Console* pConsole,int Y,int X) ///supprimer le bloc poussé
{
    pConsole->gotoLigCol(Y,X);
    std::cout<<" ";

}

///fonction qui fait afficher le bloc sur la nouvelle case vers laquelle il a été poussé
void BlocPoussable::Affichage(Console* pConsole,int Y,int X)///affiche le bloc poussé à sa nouvelle place
{
    pConsole->gotoLigCol(Y,X);
    pConsole->setColor(COLOR_GREEN);
    std::cout<<"P";

}


///getter
int BlocPoussable::getBlocPouX() const
{
    return m_coordX; ///coordonnée X
}

int BlocPoussable::getBlocPouY()const
{
    return m_coordY; ///coordonnée Y
}

///setter
void BlocPoussable::setBlocPou(int _coordX, int _coordY)
{
    m_coordX=_coordY;
    m_coordY=_coordY;
}
