#include "button.h"

/// contructors
//default constructor
Button::Button() : m_coordX(0), m_coordY(0), m_appel('/'), m_text(""), m_selection(false)
{

}

//overload constructor
Button::Button(int _coord_x, int _coord_y, char _appel, bool _color) : m_coordX(_coord_x), m_coordY(_coord_y), m_appel(_appel), m_selection(_color)
{
    attribuer_text();
}

//destructor
Button::~Button()
{
}

///Methods
//afficher button
void Button::afficher_button()
{
    // Alloue la mémoire du pointeur
    Console* pConsole = Console::getInstance();
    // Affichage avec gotoligcol et couleur
    pConsole->gotoLigCol(getcoordX(), getcoordY());
    if(getSelection()==false)
    {
        // on met la couleur puis on affiche le texte selectionné d'une certaine couleur
        pConsole->setColor(COLOR_GREEN);
        std::cout << "[" << getAppel() << "] " << getText() << std::endl;
        pConsole->setColor(COLOR_DEFAULT);
    }
    else
    {
        // on met la couleur puis on affiche le texte selectionné d'une certaine couleur
        pConsole->setColor(COLOR_RED);
        std::cout << "[" << getAppel() << "] " << getText();
        pConsole->setColor(COLOR_BLUE);
        std::cout << " -> " << std::endl;
        pConsole->setColor(COLOR_DEFAULT);
    }
    Console::deleteInstance();
}

//cliquer button
void Button::cliquer_button()
{
}

void Button::attribuer_text()
{
    //attribuer le texte en fonction du char du bouton
    //1. attribuer le texte en fonction du char du bouton
    switch(getAppel())
    {
    //1.1 si c'est le button 1
    case '1' :
        setText("Jouer une nouvelle partie");
        break;
    //1.2 si c'est le button 2
    case '2' :
        setText("Charger une partie");
        break;
    //1.3 si c'est le button 3
    case '3' :
        setText("Code secret");
        break;
    //1.4 si c'est le button 4
    case '4' :
        setText("Les Scores !");
        break;
    //1.5 si c'est le button 5
    case '5' :
        setText("Quitter");
        break;

    //pour plus tard, les autres boutons
    case '6' :
        setText("");
        break;
    }
}

///getters and setters
//getters
///on récupère la coordonnée en X
int Button::getcoordX() const
{
    return m_coordX;
}
///on récupère la coordonnée en Y
int Button::getcoordY() const
{
    return m_coordY;
}
///on récupère la lettre d'appel
char Button::getAppel() const
{
    return m_appel;
}
///on récupère le texte associé à la lettre
std::string Button::getText() const
{
    return m_text;
}
///on récupère si la couleur est changée
bool Button::getSelection() const
{
    return m_selection;
}

//setters
///on modifie la coordonnée en X
void Button::setCoordX(int _coordX)
{
    m_coordX=_coordX;
}
///on modifie la coordonnée en Y
void Button::setCoordY(int _coordY)
{
    m_coordY=_coordY;
}
///on modifie la touche associée
void Button::setFonction(char fonction_voulu)
{
    m_appel=fonction_voulu;
}
///on modifie le texte associé à la touche
void Button::setText(std::string le_text)
{
    m_text=le_text;

}
///on modifie la couleur du boolean
void Button::setSelection(bool _change)
{
    m_selection =_change;
}
