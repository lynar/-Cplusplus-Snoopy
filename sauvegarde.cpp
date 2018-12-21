#include "sauvegarde.h"

// Lire un fichier ligne par ligne
// Entrée : le chemin d'accès au fichier
void readFile(const std::string& path)
{
    std::ifstream ifs(path.c_str());
    if (ifs) // test si le fichier est bien ouvert
    {
        std::string line;
        while (std::getline(ifs, line)) // lecture ligne par ligne
        {
            std::cout << line << std::endl;
        }
        ///std::cout << "Reading " << path << " => OK" << std::endl;
        ifs.close(); // fermeture du flux
    }
    else // en cas d'erreur...
    {
        std::cout << "Cannot read " << path << std::endl;
    }
}

void writeFile(const std::string& path)
{
    // Ouverture fichier en mode "w"
    // pour le mode append, utiliser std::ios::app
    std::ofstream ofs(path.c_str(), std::ios::out);
    if (ofs)
    {
        // Ecriture dans le fichier
        float flottant = 123.456;
        ofs << "Coucou je suis une phrase" << std::endl;
        ofs << 50 << std::endl;
        ofs << flottant <<std::endl;
        ofs.close(); // fermeture du flux
    }
}
