#include "menu.h"

/// contructors
///default constructor
Menu::Menu()
{
    m_optionA.setCoordX(2);
    m_optionA.setCoordY(4);
    m_optionA.setFonction('1');
    m_optionA.attribuer_text();
    m_optionA.setSelection(true);

    m_optionB.setCoordX(4);
    m_optionB.setCoordY(30);
    m_optionB.setFonction('2');
    m_optionB.attribuer_text();
    m_optionB.setSelection(false);

    m_optionC.setCoordX(6);
    m_optionC.setCoordY(55);
    m_optionC.setFonction('3');
    m_optionC.attribuer_text();
    m_optionC.setSelection(false);

    m_optionD.setCoordX(8);
    m_optionD.setCoordY(18);
    m_optionD.setFonction('4');
    m_optionD.attribuer_text();
    m_optionD.setSelection(false);

    m_optionE.setCoordX(10);
    m_optionE.setCoordY(45);
    m_optionE.setFonction('5');
    m_optionE.attribuer_text();
    m_optionE.setSelection(false);
}

///destructor
Menu::~Menu()
{
}

///Methods
///afficher menu
void Menu::afficher_menu()
{
    getbuttonA().afficher_button();
    getbuttonB().afficher_button();
    getbuttonC().afficher_button();
    getbuttonD().afficher_button();
    getbuttonE().afficher_button();
}

///CHange le bool (donc la couleur) de l'élement en fonction de ce qu'a appuyé l'utilisateur
void Menu::afficher_la_selection(bool _increment)
{
    ///valeur du boolean changé pour A et ses cases juxtaposées
    if(getbuttonA().getSelection()==true)
    {
        m_optionA.setSelection(false);
        if(_increment==true)
        {
            m_optionB.setSelection(true);
        }
        else m_optionE.setSelection(true);
    }
    ///valeur du boolean changé pour B et ses cases juxtaposées
    else if(getbuttonB().getSelection()==true)
    {
        m_optionB.setSelection(false);
        if(_increment==true)
        {
            m_optionC.setSelection(true);
        }
        else m_optionA.setSelection(true);
    }
    ///valeur du boolean changé pour C et ses cases juxtaposées
    else if(getbuttonC().getSelection()==true)
    {
        m_optionC.setSelection(false);
        if(_increment==true)
        {
            m_optionD.setSelection(true);
        }
        else m_optionB.setSelection(true);
    }
    ///valeur du boolean changé pour D et ses cases juxtaposées
    else if(getbuttonD().getSelection()==true)
    {
        m_optionD.setSelection(false);
        if(_increment==true)
        {
            m_optionE.setSelection(true);
        }
        else  m_optionC.setSelection(true);
    }
    ///valeur du boolean changé pour E et ses cases juxtaposées
    else if(getbuttonE().getSelection()==true)
    {
        m_optionE.setSelection(false);
        if(_increment==true)
        {
            m_optionA.setSelection(true);
        }
        else m_optionD.setSelection(true);
    }
}

///selection button fonction qui permet de selectionner les items du menu
void Menu::selection_button()
{
    Jeu jeu;
    std::string code;
    char choice='c';
    bool quit = false;
    Console* pConsole = NULL;
    // Alloue la mémoire du pointeur
    pConsole = Console::getInstance();
    // Boucle événementielle
    while (!quit)
    {
        // Si on a appuyé sur une touche du clavier
        if (pConsole->isKeyboardPressed())
        {
            // Récupère le code ASCII de la touche
            int key = pConsole->getInputKey();
            if (key == 27) // 27 = touche escape
            {
                quit = true;
            }
            // si le joueur veut l'option suivante
            else if (key=='2' || key=='6' || key=='s' || key=='d' || key=='S' || key=='D')
            {
                afficher_la_selection(true);
            }
            // s'il veut la précédente
            else if (key=='4' || key=='8' || key=='q' || key=='z' || key=='Q' || key=='Z')
            {
                afficher_la_selection(false);
            }
            // s'il choisit de rentrer dans l'option avec la touche espace ou entrée
            else if (key==' ' || key ==13)
            {
                if (getbuttonA().getSelection()==true) choice='1';
                else if (getbuttonB().getSelection()==true) choice='2';
                else if (getbuttonC().getSelection()==true) choice='3';
                else if (getbuttonD().getSelection()==true) choice='4';
                else choice='5';
                switch(choice)
                {
                //1.3.1
                case '1' :
                    // Affichage avec gotoligcol et couleur
                    pConsole->gotoLigCol(13, 5);
                    pConsole->setColor(COLOR_PINK);
                    std::cout << "LET'S PLAY" << std::endl;
                    Sleep(1000);
                    system("CLS");

                    pConsole->setColor(COLOR_DEFAULT);


                    ///Commencer le jeu
                    ///initialisation
                    ///lance la boucle de jeu
                    jeu.setJeu(pConsole,3,1);
                    quit = jeu.play();

                    break;

                //1.3.2.
                case '2' :
                {

                    // Affichage avec gotoligcol et couleur
                    system("cls");
                    std::string chargement;
                    pConsole->setColor(COLOR_PINK);
                    std::cout << "Entrez le nom d'un fichier" << std::endl;
                    std::cin >> chargement;
                    system("cls");

                    if(jeu.Chargement(pConsole,"Sauvegarde/" + chargement + ".txt"))
                    {
                        quit = jeu.play();
                    }

                    break;
                }

                //1.3.3.
                case '3' :
                    fflush(stdin);
                    // Affichage avec gotoligcol et couleur
                    pConsole->gotoLigCol(13, 5);
                    pConsole->setColor(COLOR_PINK);
                    ///affichage du texte pour les codes
                    std::cout << "LET'S CHEAT" << std::endl;
                    pConsole->gotoLigCol(14, 5);
                    std::cout << "ENTER YOU SECRET CODE" << std::endl;
                    pConsole->setColor(COLOR_DEFAULT);
                    Sleep(1500);
                    std::cin >> code; ///donner le code de triche
                    triche(code);
                    break;

                //1.3.4.
                case '4' :
                    // Affichage avec gotoligcol et couleur
                    system("CLS");
                    pConsole->gotoLigCol(5, 5);
                    pConsole->setColor(COLOR_WHITE);
                    std::cout << "SCORES" << std::endl;
                    chargeScore(pConsole);
                    system("pause");
                    break;

                //1.3.5.
                case '5' :
                    // Affichage avec gotoligcol et couleur
                    pConsole->gotoLigCol(13, 5);
                    pConsole->setColor(COLOR_PINK);
                    std::cout << "WE WILL MISS YOU... :(" << std::endl;
                    pConsole->gotoLigCol(14, 5);
                    std::cout <<"SEE YOU SOON " <<std::endl;
                    Sleep(1500);
                    quit=true; ///return 0;
                    break;
                }
            }
            system("CLS");
            afficher_menu();
        }
    }
    // Libère la mémoire du pointeur !
    Console::deleteInstance();
}

///getters and setters
//getters
Button Menu::getbuttonA() const
{
    return m_optionA;
}
Button Menu::getbuttonB() const
{
    return m_optionB;
}
Button Menu::getbuttonC() const
{
    return m_optionC;
}
Button Menu::getbuttonD() const
{
    return m_optionD;
}
Button Menu::getbuttonE() const
{
    return m_optionE;
}
