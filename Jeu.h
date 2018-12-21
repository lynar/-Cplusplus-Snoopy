#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED

#include "Niveau.h"
#include <sstream>
#include <iostream>
#include <string>
#include "pagedegarde.h"

class Jeu  ///classe jeu controle toute la boucle de jeu
{
private:

    ///variable objet global
    Niveau niveau;
    Console* pConsole;
    Snoopy snoopy;
    Ball ball;
    ///attributs de la classe
    int compteuroiseaux;
    int m_temps;
    int start;
    int m_score;

public:
    ///constructeur
    Jeu();
    ///constructeur surchargé
    Jeu(Console* pconsole);
    ///destructeur
    ~Jeu();

    ///getter et setter des attributs
    int getScore();
    void setJeu(Console* pconsole,int vie,int niveau);

    ///methodes des controles
    int play(); ///boucle du jeu
    void AffichageOiseauxcompteur(); ///affichage du conteur d'oiseau par niveau
    void AffichageTemps(); ///affichage du temps par niveau
    void AffichageScore(); ///affichage du score à chaque niveau
    void Save(const std::string& path); ///sauvegarder une partie
    int Chargement(Console* pconsole,const std::string& path); ///chargement d'une partie
    void Perdu(); ///fonction qui décrémente les vie et remet le timeur à zero si condition de perte
    ///FONCTIONS DE MOUVEMENTS DES OBJETS -> SNOOPY ET BALLE
    int Mouvementmanuel();//snoopy
    void Mouvementdynamique();//ball


};

#endif // JEU_H_INCLUDED
