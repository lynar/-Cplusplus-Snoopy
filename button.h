#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED

#include "console.h"

class Button
{
private:
    // attributes
    int m_coordX;               // coordonnées en X
    int m_coordY;               // coordonnées en Y
    char m_appel;               // l'action qu'il va faire
    std::string m_text;         // text associé a l'action
    bool m_selection;           // Savoir si on color le texte differement s'il on est sur sa case

public:
    //constructors & destructor
    Button();
    Button(int _coord_x, int _coord_y, char _appel, bool _color);
    ~Button();

    //methods
    void afficher_button();
    void cliquer_button();  ///a faire
    void attribuer_text();

    //getters & setters
    ///getters
    int getcoordX() const;
    int getcoordY() const;
    char getAppel() const;
    std::string getText() const;
    bool getSelection() const;
    ///setters
    void setCoordX(int _coordX);
    void setCoordY(int _coordY);
    void setFonction(char fonction_voulu);
    void setText(std::string le_text);
    void setSelection(bool _change);
};


#endif // BUTTON_H_INCLUDED
