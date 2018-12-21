#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "button.h"
#include "Jeu.h"
#include "pagedegarde.h"


class Menu
{
private: //attributs
    Button m_optionA;       // Jouer
    Button m_optionB;       // Charger
    Button m_optionC;       // code secret
    Button m_optionD;       // meilleur score
    Button m_optionE;       // quitter

public:
    //constructor & destructor
    Menu();
    ~Menu();

    //methods
    void afficher_menu();
    void selection_button();  ///a faire
    void afficher_la_selection(bool _increment);

    //getters & setters
    Button getbuttonA() const;
    Button getbuttonB() const;
    Button getbuttonC() const;
    Button getbuttonD() const;
    Button getbuttonE() const;
};

#endif // MENU_H_INCLUDED
