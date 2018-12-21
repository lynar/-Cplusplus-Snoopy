#include "pagedegarde.h"
#include "console.h"


void pagedegarde() ///.affichage de la page de garde
{
    Console* pConsole = NULL;
    bool quit = false;
    // Alloue la mémoire du pointeur
    pConsole = Console::getInstance();
    // Affichage avec gotoligcol et couleur
    pConsole->gotoLigCol(4,0);
    pConsole->setColor(COLOR_TURQUOISE);
    // affichage du Snoopy's revenge
    std::cout <<"    ****                                                       "<< std::endl;                  //snoopy
    std::cout <<"   *                                                           "<< std::endl;                  //snoopy
    std::cout <<"   *                                                *   ****   "<< std::endl;                  //snoopy
    std::cout <<"    ***   * ***    *****   *****   *****  *     *   *  *       "<< std::endl;                  //snoopy
    std::cout <<"       *  *    *   *   *   *   *   *   *   *   *        ***    "<< std::endl;                  //snoopy
    std::cout <<"       *  *    *   *   *   *   *   *   *    * *            *   "<< std::endl;                  //snoopy
    std::cout <<"   ****   *    *   *****   *****   *****     *         ****    "<< std::endl;                  //snoopy
    std::cout <<"                                   *         *                 "<< std::endl;                  //snoopy
    std::cout <<"                                   *         *                  "<< std::endl;                 //snoopy
    pConsole->setColor(COLOR_RED);
    std::cout <<"                   *****";
    pConsole->setColor(COLOR_TURQUOISE);
    std::cout <<"           *         *                             "<< std::endl;
    pConsole->setColor(COLOR_RED);
    std::cout <<"                   *    *                                                 "<< std::endl;       //revenge
    std::cout <<"                   *    *  *****             *****                  ***** "<< std::endl;       //revenge
    std::cout <<"                   * * *   *       *     *   *       * ***   *****  *     "<< std::endl;       //revenge
    std::cout <<"                   *  *    ***      *   *    ***     *    *  *   *  ***   "<< std::endl;       //revenge
    std::cout <<"                   *   *   *         * *     *       *    *  *   *  *     "<< std::endl;       //revenge
    std::cout <<"                   *    *  *****      *      *****   *    *  *****  ***** "<< std::endl;       //revenge
    std::cout <<"                                                                 *        "<< std::endl;       //revenge
    std::cout <<"                                                               * *        "<< std::endl;       //revenge
    std::cout <<"                                                              *  *        "<< std::endl;       //revenge
    std::cout <<"                                                              ***         "<< std::endl;       //revenge
    std::cout << std::endl;
    pConsole->gotoLigCol(24,2); ///position curseur
    pConsole->setColor(COLOR_GREEN); ///affichage couleur
    std::cout <<"Project by : "<< std::endl;
    pConsole->gotoLigCol(25,2);
    std::cout << "Fabien Roussel" <<std::endl;
    pConsole->gotoLigCol(26,2);
    std::cout << "Lyna Rachdi" << std::endl;
    pConsole->setColor(COLOR_DEFAULT);
    std:: cout << "Appuyez sur touche pour continuer" << std:: endl;
    while (!quit)
    {
        // Si on a appuyé sur une touche du clavier
        if (pConsole->isKeyboardPressed())
        {
            // Récupère le code ASCII de la touche
            pConsole->getInputKey();
            quit = true;
        }
    }
    system("CLS");
    pConsole->setColor(COLOR_DEFAULT);
//0. Declaration des var
    Menu mein_menu; ///objet menu créé appel du menu qui contient la boucle de jeu
    //1. Initialisation des var
    //2. affichage
    mein_menu.afficher_menu(); ///lacement du menu
    //3. selection button
    mein_menu.selection_button(); ///déplacement curseur sur bouton
    Console::deleteInstance();

}

void triche(std::string& code)
{
    Jeu jeu;
    bool quit=false;
    Console* pConsole = NULL;
    // Alloue la mémoire du pointeur
    pConsole = Console::getInstance();

    if (code == "fabien")
    {
        system("CLS");
        jeu.setJeu(pConsole,3,2);
        quit = jeu.play();
    }
    else if (code == "lyna")
    {
        system("CLS");
        jeu.setJeu(pConsole,3,3);
        quit = jeu.play();
    }
    else
    {
        std::cout<<"Vous ne savez pas comment tricher???"<< std::endl;
        std::cout<<"Essayez un autre code:"<<std::endl;
        std::cin >>code;
        triche(code);
    }
}

void meilleurScore(Console* pConsole, int m_score)
{
    std::string prenom;
    system("CLS");
    pConsole->setColor(COLOR_WHITE);
    pConsole->gotoLigCol(10,10);
    std::cout<<"BRAVO VOUS AVEZ GAGNE"<<std::endl;
    pConsole->gotoLigCol(10,11);
    std::cout<<"Pour enregistrer votre score saisissez votre prenom"<<std::endl;
    std::cin >> prenom;

    std::string best = "Meilleur Score/Meilleurs.txt";
    // Ouverture fichier en mode "w"
    // pour le mode append, utiliser std::ios::app
    std::ofstream ofs(best.c_str(), std::ios::out);
    if (ofs)
    {
        // Ecriture dans le fichier
        ofs << prenom << std::endl;
        ofs << m_score << std::endl;
        ofs.close(); // fermeture du flux
    }
}

void chargeScore(Console* pConsole)
{
    std::string path="Meilleur Score/Meilleurs.txt";
    std::ifstream ifs(path.c_str());
    if (ifs) // test si le fichier est bien ouvert
    {
        std::string line;
        while (std::getline(ifs, line)) // lecture ligne par ligne
        {
            std::cout << line << std::endl;
        }
        ifs.close(); // fermeture du flux
    }
    else // en cas d'erreur...
    {
        std::cout << "Cannot read " << path << std::endl;
    }
}

