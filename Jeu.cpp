
#include "Jeu.h"
#include <iomanip>

///constructeur
Jeu::Jeu()
{
}

///destructeur
Jeu::~Jeu()
{
}

///boucle de jeu
void Jeu::setJeu(Console* pconsole,int vie,int niv)
{
    pConsole = pconsole; ///initialise la console
    std::ostringstream oss; ///lecture de fichier texte
    oss << niv; ///lecture du niveau
    std::string temp = "Niveau/niveau" + oss.str() + ".txt"; ///appel du fichier texte en fonction du niveau

    start=clock(); ///initialisation pour le timeur
    compteuroiseaux=0;///intitialisation du compteur
    ///URTILISATION DES FONCTIONS DE LA CLASSE NIVEAU
    niveau.LoadFromFile(temp); ///fonction qui permet de mettre en mémoire la map
    niveau.setVie(vie); ///setter de vie
    niveau.setNiveau(niv);///setter de niveau
    niveau.afficherMatrice(pConsole);
    ///AFFICHAGE A LA CONSOLE
    AffichageOiseauxcompteur();
    snoopy = niveau.getSnoopie();
    ball = niveau.getBall();
}

///methode de chargement d'une partie sauvegardée
int Jeu::Chargement(Console* pconsole,const std::string& path)
{
    pConsole = pconsole;
    std::ifstream ifs(path.c_str());
    if (ifs) // test si le fichier est bien ouvert
    {
        std::string line;
        int value;

        std::getline(ifs, line);
        std::istringstream (line) >> value;
        niveau.setNiveau( value);

        std::getline(ifs, line);
        std::istringstream (line) >> value;
        niveau.setVie(value);

        std::getline(ifs, line);
        std::istringstream (line) >> value;
        compteuroiseaux = value;

        std::getline(ifs, line);
        std::istringstream (line) >> value;
        start=clock()-(60-value)*CLOCKS_PER_SEC;

        std::getline(ifs, line);
        std::istringstream (line) >> value;
        m_score = value;

        std::getline(ifs, line);
        niveau.LoadFromFile(line);
        niveau.afficherMatrice(pConsole);
        AffichageOiseauxcompteur();
        snoopy = niveau.getSnoopie();
        ball = niveau.getBall();

        ///std::cout << "Reading " << path << " => OK" << std::endl;
        ifs.close(); // fermeture du flux
        return true;
    }
    else // en cas d'erreur...
    {
        std::cout << "Cannot read " << path << std::endl;
        return false;
    }
}

void Jeu::Mouvementdynamique() ///fonction d'action de la ballz qui est indépendant du reste du jeu
{
    int x = ball.getBallPosx(), ///reucperr les coordonnées de la balle
        y = ball.getBallPosy();

    bool modif = false;

    int depx = ball.getdepx(),///recupérer les coordonnées de déplacement
        depy = ball.getdepy();


    ///ensemble de fonction qui sert à Rafraichir la Boule
    ball.deleteAffichage(pConsole);
    niveau.setmatrice(x,y,' ');



    if(x + depx > 19 || x + depx < 0 || (niveau.getmatrice(x + depx,y)!=' ' && niveau.getmatrice(x + depx,y)!='S') )
    {
        ball.inverseX(); ///deplacement pour les choc avec les murs de haut et de bas de la matrice
        modif = true;
    }


    if(y + depy > 9 || y + depy < 0 || (niveau.getmatrice(x,y + depy)!=' ' &&  niveau.getmatrice(x,y + depy)!='S') )
    {
        ball.inverseY();///deplacement pour les choc avec les murs de droite et de gauche de la matrice
        modif = true;
    }


    if(!modif && (niveau.getmatrice(x + depx,y + depy)!=' ' &&  niveau.getmatrice(x + depx,y + depy)!='S'))
    {
        ball.inverseX();
        ball.inverseY();
    }

    ball.deplacementBall(); ///appel de la methode qui déplace la matrice

    ball.Affichage(pConsole);///affichage de la ball

    x = ball.getBallPosx(); //donnée la nouvelle position à la balle
    y = ball.getBallPosy();
    niveau.setmatrice(x,y,'B');
}

int Jeu::Mouvementmanuel() ///fonction d'action sur la matrice
{
    if (pConsole->isKeyboardPressed())
    {
        /// Récupère le code ASCII de la touche
        int key = pConsole->getInputKey();
        bool blok = false;
        ///Recupere les coordonnées de snoopy
        int x=snoopy.getcoordX(),
            y=snoopy.getcoordY();

        ///Rafraichir snoopy
        snoopy.deleteAffichage(pConsole);
        niveau.setmatrice(x,y,' ');

        switch(key) ///switch de controle des touches pendant une partie
        {
        case 'a': ///pour casser un bloc
        {
            //couper
            while(!pConsole->isKeyboardPressed());

            BlocCassable temp;
            int key2 = pConsole->getInputKey();

            switch(key2) ///pour savoir dans qu'elle direction snoopy doit casser
            {
            case '8':///en fonction de la direction imposée
            case 'z':
                if(niveau.getmatrice(x,y-1)=='C')
                {
                    temp.deleteAffichage(pConsole,y-1,x); ///supprime le bloc cassable
                    niveau.setmatrice(x,y-1,' ');
                }
                break;

            case '2':///en fonction de la direction imposée
            case 's':
                if(niveau.getmatrice(x,y+1)=='C')
                {
                    temp.deleteAffichage(pConsole,y+1,x);///supprime le bloc cassable
                    niveau.setmatrice(x,y+1,' ');
                }
                break;

            case '4':///en fonction de la direction imposée
            case 'q':
                if(niveau.getmatrice(x-1,y)=='C')
                {
                    temp.deleteAffichage(pConsole,y,x-1);///supprime le bloc cassable
                    niveau.setmatrice(x-1,y,' ');
                }
                break;

            case '6':///en fonction de la direction imposée
            case 'd':
                if(niveau.getmatrice(x+1,y)=='C')
                {
                    temp.deleteAffichage(pConsole,y,x+1);///supprime le bloc cassable
                    niveau.setmatrice(x+1,y,' ');
                }
                break;
            }

            break;

        }

        case '8':///en fonction de la touche
        case 'z':

            if(y>0)
            {
                //blindage
                switch(niveau.getmatrice(x,y-1))
                {
                case 'O':
                    compteuroiseaux++; ///compteur d'oiseur
                    AffichageOiseauxcompteur(); ///affiche le nombre d'oiseaux mangé
                    break;
                case 'T': ///bloc qui tue
                {
                    ///perdu new level
                    Perdu();
                    blok=true;
                    break;
                }
                case 'C': ///detruire les blocs cassables
                    blok=true;
                    break;
                case 'Q': ///detruire les blocs cassables
                    blok=true;
                    break;
                case 'P': ///pousser les blocs
                    if(y>1 && niveau.getmatrice(x,y-2)==' ')
                    {
                        BlocPoussable temp;
                        temp.deleteAffichage(pConsole,y-1,x);
                        temp.Affichage(pConsole,y-2,x);
                        niveau.setmatrice(x,y-1,' ');
                        niveau.setmatrice(x,y-2,'Q');///donne un autre nom au bloc poussé une fois qu'ils ont été poussé pour qu'on ne puisse pas les pousser une deuxieme fois
                        //bouge caillou
                    }
                    else
                        blok = true;

                    break;
                }

                if(!blok)
                    snoopy.deplacerSnoopy(key);

            }


            break;

        case '2':///en fonction de la touche
        case 's':
            if(y<9)
            {
                //blindage
                switch(niveau.getmatrice(x,y+1))
                {
                case 'O':
                    compteuroiseaux++;///compteur d'oiseur
                    AffichageOiseauxcompteur();///affiche le nombre d'oiseaux mangé
                    break;
                case 'T':
                {
                    //perdu new level
                    Perdu();
                    blok=true;
                    break;
                }
                case 'Q': ///detruire les blocs cassables
                    blok=true;
                    break;
                case 'C':
                    blok=true;
                    break;
                case 'P':
                    if(y<8 && niveau.getmatrice(x,y+2)==' ')
                    {
                        BlocPoussable temp;
                        temp.deleteAffichage(pConsole,y+1,x);
                        temp.Affichage(pConsole,y+2,x);
                        niveau.setmatrice(x,y+1,' ');
                        niveau.setmatrice(x,y+2,'Q');///donne un autre nom au bloc poussé une fois qu'ils ont été poussé pour qu'on ne puisse pas les pousser une deuxieme fois
                        //bouge caillou
                    }
                    else
                        blok = true;

                    break;
                }


                if(!blok)
                    snoopy.deplacerSnoopy(key);

            }
            break;

        case '4':///en fonction de la touche
        case 'q':
            if(x>0)
            {
                //blindage
                switch(niveau.getmatrice(x-1,y))
                {
                case 'O':
                    compteuroiseaux++;///compteur d'oiseur
                    AffichageOiseauxcompteur();///affiche le nombre d'oiseaux mangé
                    break;
                case 'T':
                {
                    //perdu new level
                    Perdu();
                    blok=true;
                    break;
                }
                case 'Q': ///detruire les blocs cassables
                    blok=true;
                    break;
                case 'C':
                    blok=true;
                    break;
                case 'P':
                    if(x>1 && niveau.getmatrice(x-2,y)==' ')
                    {
                        BlocPoussable temp; ///pour bloquer les bloc poussé une fois qu'ils ont été poussé
                        temp.deleteAffichage(pConsole,y,x-1);
                        temp.Affichage(pConsole,y,x-2);
                        niveau.setmatrice(x-1,y,' ');
                        niveau.setmatrice(x-2,y,'Q'); ///donne un autre nom au bloc poussé une fois qu'ils ont été poussé pour qu'on ne puisse pas les pousser une deuxieme fois
                        //bouge caillou
                    }
                    else
                        blok = true;


                    break;
                }

                if(!blok)
                    snoopy.deplacerSnoopy(key);
            }
            break;

        ///Quitte le jeu pendant une partie
        case 'e':
            return true;
            break;
        ///pour faire une sauvegarde durant le jeu
        case 'l':
        {
            system("cls");
            std::string sauvegarde;
            pConsole->setColor(COLOR_PINK);
            std::cout << "Entrez le nom d'un fichier" << std::endl;
            std::cin >> sauvegarde;
            niveau.setmatrice(snoopy.getcoordX(),snoopy.getcoordY(),'S');
            Save(sauvegarde); ///appel de la fonction sauvegarde
        }

        ///faire un retour menu pendant une partie
        case 'm':
            return false;
            break;
        ///mettre le jeu en pause avec disparition de snoopy
        case 'p':
            while( pConsole->getInputKey()!='p');//snoopy  disparait de l'écran
            start=clock()-(60-m_temps)*CLOCKS_PER_SEC;///pour réinitialiser le timeur au temps avant la pause
            break;


        case '6':///en fonction de la touche action sur le jeu
        case 'd':
            if(x<19)
            {
                //blindage
                switch(niveau.getmatrice(x+1,y))
                {
                case 'O':///cas de l'oiseau(augemnte le nombre d'oiseaux)
                    compteuroiseaux++;///compteur d'oiseur
                    AffichageOiseauxcompteur();///affiche le nombre d'oiseaux mangé
                    break;
                case 'T': ///cas du bloc tueur (perte de vie)
                {
                    ///perdu new level
                    Perdu();
                    blok=true;
                    break;
                }
                case 'Q': ///pour éviter qu'un bloc poussable soit poussable deux fois
                    blok=true;
                    break;
                case 'C': ///bloc cassable
                    blok=true;
                    break;
                case 'P':
                    if(x<18 && niveau.getmatrice(x+2,y)==' ')
                    {
                        BlocPoussable temp;
                        temp.deleteAffichage(pConsole,y,x+1);
                        temp.Affichage(pConsole,y,x+2);
                        niveau.setmatrice(x+1,y,' ');
                        niveau.setmatrice(x+2,y,'Q');///donne un autre nom au bloc poussé une fois qu'ils ont été poussé pour qu'on ne puisse pas les pousser une deuxieme fois
                        //bouge caillou
                    }
                    else
                        blok = true;
                    break;
                }

                if(!blok)
                    snoopy.deplacerSnoopy(key);
            }

            break;
        }

        snoopy.Affichage(pConsole); ///pour afficher snoopy
        niveau.setmatrice(snoopy.getcoordX(),snoopy.getcoordY(),'S');///pour mettre en place la matrice
    }
    return 3;
}

int Jeu::play()
{
    int retour;
    int temporaire_temps;
    m_score=0;

    do
    {
        m_temps =60-(clock()-start)/CLOCKS_PER_SEC; ///fonction qui met le timeur a 60s et le décrémente
        if(temporaire_temps!=m_temps)///evite le clignotement
        {
            temporaire_temps=m_temps;
            AffichageTemps();///affichage du timeur
            AffichageScore();///affichage du score
            ///Mouvement de la balle
            Mouvementdynamique();
        }

        ///Mouvement de Snoopy
        retour = Mouvementmanuel();
        if(retour!=3)
            return retour;

        ///Condition de fin de jeu
        if(compteuroiseaux==4 && niveau.getNiveau()==3)
        {
            meilleurScore(pConsole, m_score);///enregistrement du score dans la fonction meilleur score
            return false;
        }
        else if(compteuroiseaux==4 ) ///pour le passage de niveau
        {
            int tempvie = niveau.getVie();///garder le nombre de vie restant en mémoire
            this->setJeu(pConsole,tempvie,niveau.getNiveau()+1);///fait passer au niveau suivant
            m_score+=100*m_temps; ///remet le timeur à 60s
        }
        else if(m_temps==0) ///condition si le temps est fini
        {
            Perdu();///appel de la fonction perdu qui enlève une vie et remet le timeur à 60s
        }
        else if(snoopy.getcoordX() == ball.getBallPosx() && snoopy.getcoordY() == ball.getBallPosy()) ///condition si la ball et snoopy rentre en contacte
        {
            Perdu();///appel de la fonction perdu qui enlève une vie et remet le timeur à 60s
        }

    }
    while (niveau.getVie()>0);///boucle de condition pour que le jeu fonctionne

    return false;
}

///fonction de sauvegarde
void Jeu::Save(const std::string& path)
{

    ///creation des paths d'écriture
    //path valeur
    std::string config = "Sauvegarde/" + path + ".txt";
    //path matrice
    std::string matrice = "Sauvegarde/" + path + "_mat.txt";
    // Ouverture fichier en mode "w"
    // pour le mode append, utiliser std::ios::app
    std::ofstream ofs(config.c_str(), std::ios::out);
    if (ofs)
    {
        // Ecriture dans le fichier
        ofs << niveau.getNiveau() << std::endl; ///niveau
        ofs << niveau.getVie() << std::endl; ///nb vie
        ofs << compteuroiseaux <<std::endl; ///nb oiseaux
        ofs << m_temps <<std::endl; ///timeur
        ofs << m_score <<std::endl; ///le score
        ofs << matrice; ///la matrice
        ofs.close(); // fermeture du flux
    }


    std::ofstream ofs2(matrice.c_str(), std::ios::out);
    if (ofs2)
    {
// Ecriture dans le fichier
        for(int i=0; i<10; i++)
        {
            for(int j=0; j<20; j++)
            {
                ofs2 << niveau.getmatrice(j,i);
            }
            ofs2 << std::endl; //Passe à la ligne après avoir afficher les 15 carateres de chaque lignes
        }
        ofs2.close(); // fermeture du flux
    }
}

void Jeu::Perdu() ///fonction qui rétabli les condition du jeu à l'initale et qui décrémente la vie en cas de perte
{
    this->setJeu(pConsole,niveau.getVie()-1,niveau.getNiveau());

}

void Jeu::AffichageOiseauxcompteur() ///affiche le nombre d'oiseau mangé dans la consol
{
    pConsole->gotoLigCol(10,25);
    pConsole->setColor(COLOR_PINK);
    std::cout<<"  Oiseaux: "<<compteuroiseaux;
}

void Jeu::AffichageTemps() ///affichage du timeur à l'écran
{
    pConsole->gotoLigCol(9,25);
    pConsole->setColor(COLOR_TURQUOISE);
    std::cout<<"  Temps restant: "<<std::setw(2)<<m_temps;
}

void Jeu::AffichageScore() ///affichage du score à l'écran
{
    pConsole->gotoLigCol(8,25);
    pConsole->setColor(COLOR_WHITE);
    std::cout<<"  Score: "<<m_score;
}

///getter de l'attribut de la classe
int Jeu::getScore()
{
    return m_score;
}


