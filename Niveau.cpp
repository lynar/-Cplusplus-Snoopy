#include "Niveau.h"

Niveau::Niveau() ///constructeur
{
    std::vector< char > vecteur(10);

    for(int i=0; i<20; i++)
    {
        matrice.push_back(vecteur); ///création de la matrice de char
    }
}

Niveau::~Niveau() ///destructeur
{
}

void Niveau::LoadFromFile(const std::string& path) ///fonction qui lit des fichiers texte de map des objets
{
    int coordx = 0,
        coordy = 0;
    std::ifstream ifs(path.c_str());
    if (ifs) // test si le fichier est bien ouvert
    {
        char a;
        while (ifs.get(a)) // lecture ligne par ligne
        {

            matrice[coordy][coordx]=a;

            switch(a)///switch de condition des objets sur le fichiers texte
            {
            case 'S':
            {
                snoopy.setSnoopy(coordx,coordy); ///set snoopy si sur le fichier
                break;
            }
            case 'B':
            {
                ball.setBall(coordx,coordy); ///set ball si sur le fichier
                break;
            }
            case '\n':
                coordy++;
                coordx=-1;
                break;
            }


            coordx++;
            //std::cout << a ;

        }

        ifs.close(); // fermeture du flux
    }
    else // en cas d'erreur...
    {
        std::cout << "Cannot read " << path << std::endl;
    }
}

void Niveau::afficherMatrice(Console* pConsole) ///fonction d'affichage de la matrice
{
    for(int i=0; i<3; i++)
    {
        pConsole->gotoLigCol(i+6,25);
        if(i==0)
        {
            pConsole->setColor(COLOR_GREEN);
            std::cout<<"  Niveau: "<<m_niveau;
        }
        if(i==1)
        {
            pConsole->setColor(COLOR_RED);
            std::cout<<"  Vies: "<<m_vie;
        }

    }

    pConsole->setColor(COLOR_DEFAULT);

    //Affichage Snoopy


    for(int i=0; i<10; i++)
    {

        for(int j=0; j<20; j++)
        {
            pConsole->gotoLigCol(i,j);
            switch (matrice[i][j]) ///On test chaque case de la matrice pour savoir son caractere
            {
            case 'O' :
                pConsole->setColor(COLOR_YELLOW);///attribut la couleur en fonction du caractère
                std::cout<<matrice[i][j];///donne la valeur du caractère à la matrice
                break;
            case 'Q' :
                pConsole->setColor(COLOR_GREEN);///attribut la couleur en fonction du caractère
                std::cout<<'P';///cas particulier pour que le bloc poussable ne soit poussable qu'une fois
                break;
            case 'P' :
                pConsole->setColor(COLOR_GREEN);///attribut la couleur en fonction du caractère
                std::cout<<matrice[i][j];///donne la valeur du caractère à la matrice
                break;
            case 'C' :
                pConsole->setColor(COLOR_TURQUOISE);///attribut la couleur en fonction du caractère
                std::cout<<matrice[i][j];///donne la valeur du caractère à la matrice
                break;
            case 'T' :
                pConsole->setColor(COLOR_PINK);///attribut la couleur en fonction du caractère
                std::cout<<matrice[i][j];///donne la valeur du caractère à la matrice
                break;
            default:

                std::cout<<matrice[i][j];///donne la valeur du caractère à la matrice
                break;
            }
        }
        std::cout<<std::endl; //Passe à la ligne après avoir afficher les 15 carateres de chaque lignes
    }

    snoopy.Affichage(pConsole); ///affiche snoopy
    ball.Affichage(pConsole); ///affiche la ball

    pConsole->setColor(COLOR_WHITE);
    pConsole->gotoLigCol(10,0);
    std::cout <<"*********************"<<std::endl;
}

///getter
int Niveau::getVie() const
{
    return m_vie;
}

int Niveau::getScore() const
{
    return m_score;
}


int Niveau::getNiveau() const
{
    return m_niveau;
}

Snoopy Niveau::getSnoopie() const
{
    return snoopy;
}

Ball Niveau::getBall() const
{
    return ball;
}

char Niveau::getmatrice(int x, int y) const
{
    return matrice[y][x];
}

///setter
void Niveau::setmatrice(int x, int y, char value)
{
    matrice[y][x] = value;
}


void Niveau::setVie(int nb)
{
    m_vie=nb;
}

void Niveau::setNiveau(int level)
{
    m_niveau=level;
}




