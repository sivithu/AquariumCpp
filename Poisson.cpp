//
// Created by Vithursan Sivakumaran on 27/01/2020.
//

#include "Poisson.h"

Poisson::Poisson() {}

Poisson::Poisson(const std::string &nom, char sexe, Races type) : nom(nom), sexe(sexe), type(type) {}

Poisson::~Poisson() {

}

const std::string &Poisson::getNom() const {
    return nom;
}

void Poisson::setNom(const std::string &nom) {
    Poisson::nom = nom;
}

char Poisson::getSexe() const {
    return sexe;
}

void Poisson::setSexe(char sexe) {
    Poisson::sexe = sexe;
}

Races Poisson::getType() const {
    return type;
}

void Poisson::setType(Races type) {
    Poisson::type = type;
}

bool Poisson::isCarnivore() {
    if(this->getType() == Races::MEROU || this->getType() == Races::THON || this->getType() == Races::POISSON_CLOWN) {
        return true;
    }
    return false;
}

bool Poisson::isHerbivore() {
    if(this->getType() == Races::SOLE || this->getType() == Races::BAR || this->getType() == Races::CARPE) {
        return true;
    }
    return false;
}

int Poisson::getPv() const {
    return pv;
}

void Poisson::setPv(int pv) {
    Poisson::pv = pv;
}
