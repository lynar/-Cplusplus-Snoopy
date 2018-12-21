#ifndef PAGEDEGARDE_H_INCLUDED
#define PAGEDEGARDE_H_INCLUDED

#include "console.h"
#include "windows.h"
#include "menu.h"
#include "Jeu.h"

void pagedegarde(); ///prototype affichage entrée du jeu
void triche(std::string& code);///prototype cheatcode
void meilleurScore(Console* pConsole, int m_score);///pour enregistrer les meilleures scores
void chargeScore(Console* pConsole);///pour afficher les scores
#endif // PAGEDEGARDE_H_INCLUDED
