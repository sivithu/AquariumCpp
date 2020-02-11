//
// Created by Vithursan Sivakumaran on 27/01/2020.
//

#include "Aquarium.h"
#include "Poisson.h"
#include <vector>
#include <iostream>

Aquarium::Aquarium(std::vector<Poisson> poissons, std::vector<Algue> algues) : poissons(poissons), algues(algues) {}

Aquarium::~Aquarium() {

}

const std::vector<Algue> &Aquarium::getAlgues() const {
    return algues;
}

void Aquarium::setAlgues(const std::vector<Algue> &algues) {
    Aquarium::algues = algues;
}

const std::vector<Poisson> &Aquarium::getPoissons() const {
    return poissons;
}

void Aquarium::setPoissons(const std::vector<Poisson> &poissons) {
    Aquarium::poissons = poissons;
}

void Aquarium::addPoission(Poisson &p) {
    poissons.push_back(p);
}

void Aquarium::passerTour() {
    std::vector<Poisson>::iterator it, end;
    std::vector<Poisson> p = poissons;
    std::cout << "-------------TOUR-------------" << std::endl << "------------AVANT------------" << std::endl;
    afficherDetails();
    if(!poissons.empty()){
        for(it = poissons.begin(); it != poissons.end(); ++it) {
            if(it->isCarnivore()) {
                //manger Algue
                if(!algues.empty()) {
                    if(it->getPv() <= 5) {
                        auto val = algues.begin() + (rand() % algues.size());
                        it->setPv(it->getPv() + 3);
                        val->setPv(val->getPv() - 2);
                        std::cout << it->getNom() << " a mangé une algue ////////// pv : " << it->getPv() <<std::endl;
                        if(val->getPv() <= 0) {
                            std::cout << " Algue est mort " << std::endl;
                            algues.erase(val);
                        }
                    }
                }
            } else {
                //manger Poisson
                if(!p.empty()) {
                    if(it->getPv() <= 5) {
                        int randIndex = rand() % p.size();
                        if(it->getNom() != p[randIndex].getNom() && it->getType() != p[randIndex].getType()) {
                            auto val = poissons.begin() + randIndex;
                            //test
                            //std::cout << "it : " << it->getNom() << " // p : " << p[randIndex].getNom() << " // erase : " << val->getNom() << std::endl;
                            it->setPv(it->getPv() + 5);
                            val->setPv(val->getPv() - 4);
                            std::cout << it->getNom() << " a mangé " << val->getNom() << " ////////// " << it->getPv() << " :: " << val->getPv() << std::endl;
                            if(val->getPv() <= 0) {
                                std::cout << val->getNom() << " est mort " << std::endl;
                                p.erase(val);
                            }
                        }
                    }
                }
            }
        }
    }
    if(p.size() != poissons.size()) {
        this->setPoissons(p);
    }
    gestionVie();
    reproduction();
    std::cout << "------------APRES------------" << std::endl;
    afficherDetails();
    std::cout << "------------END------------" << std::endl;
}

void Aquarium::gestionVie() {
    std::vector<Algue>::iterator itA, endA;
    if(!algues.empty()){
        for(itA = algues.begin(), endA = algues.end(); itA != endA; ++itA) {
            itA->setPv(itA->getPv() + 1);
            itA->setAge(itA->getAge() + 1);
            if(itA->getAge() >= 20) {
                std::cout << "Une algue est mort de vieillesse" << std::endl;
                algues.erase(itA);
            }
        }
    }
    std::vector<Poisson>::iterator itP, endP;
    if(!poissons.empty()){
        for(itP = poissons.begin(), endP = poissons.end(); itP != endP; ++itP) {
            itP->setPv(itP->getPv() - 1);
            itP->setAge(itP->getAge() + 1);
            if(itP->getPv() <= 0) {
                std::cout << itP->getNom() << " est mort" << std::endl;
                poissons.erase(itP);
            }
            if(itP->getAge() >= 20) {
                std::cout << itP->getNom() << " est mort de vieillesse" << std::endl;
                poissons.erase(itP);
            }
        }
    }
}

void Aquarium::afficherDetails() {
    std::vector<Algue>::iterator itA, endA;
    std::vector<Poisson>::iterator itP, endP;
    if(!algues.empty()){
        std::cout << "   ------------Algue-------------   " << std::endl;
        for(itA = algues.begin(), endA = algues.end(); itA != endA; ++itA) {
            std::cout << "PV : " << itA->getPv() << std::endl;
        }
    }
    if(!poissons.empty()){
        std::cout << "   ------------Poisson-------------   " << std::endl;
        for(itP = poissons.begin(), endP = poissons.end(); itP != endP; ++itP) {
            std::string val = itP->isHerbivore()?"Herbivore":"Carnivore";
            std::cout << "Nom : " << itP->getNom() << "; Sexe : " << itP->getSexe() << "; Race : " << itP->getType() << "; " << val << "; PV : " << itP->getPv() << std::endl;
        }
    }
}

void Aquarium::addAlgue(Algue &a) {
    algues.push_back(a);
}

void Aquarium::reproduction() {
    std::vector<Algue>::iterator itA, endA;
    if(!algues.empty()){
        for(itA = algues.begin(), endA = algues.end(); itA != endA; ++itA) {
            if(itA->getPv() >= 10) {
                itA->setPv(itA->getPv() - 5);
                Algue *a = new Algue();
                a->setPv(a->getPv() - 5);
                algues.push_back(*a);
                std::cout << "Une algue a donné naissance à une autre algue" << std::endl;
            }
        }
    }
    std::vector<Poisson>::iterator itP, endP;
    std::vector<Poisson> p = poissons;
    if(!poissons.empty()){
        for(itP = poissons.begin(), endP = poissons.end(); itP != endP; ++itP) {
            if(itP->getPv() >= 5) {
                int randIndex = rand() % p.size();
                if(itP->getNom() != p[randIndex].getNom() && itP->getType() == p[randIndex].getType() && itP->getSexe() != p[randIndex].getSexe()) {
                    auto val = poissons.begin() + randIndex;
                    Poisson *np = new Poisson(itP->getNom() + "-" + val->getNom() + "_" + "son", 'M', itP->getType());
                    poissons.push_back(*np);
                    std::cout << itP->getNom() << " et " << val->getNom() << " ont donné naissance à " << np->getNom() << std::endl;
                }
            }
        }
    }
}
