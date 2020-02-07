//
// Created by Vithursan Sivakumaran on 27/01/2020.
//

#ifndef AQUARIUM_POISSON_H
#define AQUARIUM_POISSON_H
#include <string>   // pour std::string

enum Races {MEROU, THON, POISSON_CLOWN, SOLE, CARPE, BAR};

class Poisson {
private:
    std::string nom;
    char sexe;
    Races type;
    int pv = 10;
public:
    Poisson();
    Poisson(const std::string &nom, char sexe, Races type);
    ~Poisson();
    const std::string &getNom() const;
    void setNom(const std::string &nom);
    char getSexe() const;
    void setSexe(char sexe);
    Races getType() const;
    void setType(Races type);
    int getPv() const;
    void setPv(int pv);
    bool isCarnivore();
    bool isHerbivore();
};

#endif //AQUARIUM_POISSON_H

