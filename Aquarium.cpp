//
// Created by Vithursan Sivakumaran on 27/01/2020.
//

#include "Aquarium.h"
#include "Poisson.h"
#include <vector>
#include <iostream>

Aquarium::Aquarium(std::vector<Poisson> poissons, std::vector<Algue> algues) : poissons(poissons), algues(algues) {}

Aquarium::~Aquarium() {}

const std::vector<Algue> &Aquarium::getAlgues() const {
    return algues;
}

void Aquarium::setAlgues(const std::vector<Algue> &algues) {
    this->algues = algues;
}

const std::vector<Poisson> &Aquarium::getPoissons() const {
    return poissons;
}

void Aquarium::setPoissons(const std::vector<Poisson> &poissons) {
    this->poissons = poissons;
}

void Aquarium::addPoisson(Poisson &p) {
    this->poissons.push_back(p);
}

void Aquarium::passerTour() {
    std::vector<Poisson>::iterator it, end;
    std::vector<Poisson> p = poissons;
    std::cout << "-------------TOUR-------------" << std::endl << "------------AVANT------------" << std::endl;
    afficherDetails();
    if(!poissons.empty()){
        for(it = poissons.begin(); it != poissons.end(); ++it) {
            if(it->isHerbivore()) {
                //manger Algue
                if(!algues.empty()) {
                    if(it->getPv() <= 5) {
                        auto val = algues.begin() + (rand() % algues.size());
                        it->setPv(it->getPv() + 3);
                        val->setPv(val->getPv() - 2);
                        std::cout << it->getNom() << " a mangé une algue ////////// pv : " << it->getPv() <<std::endl;
                        gestionVieAlgue();
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
                            gestionViePoisson();
                        }
                    }
                }
            }
        }
    }
    gestionVie();
    reproduction();
    std::cout << "------------APRES------------" << std::endl;
    afficherDetails();
    std::cout << "------------END------------" << std::endl;
}

void Aquarium::gestionVie() {
    gestionVieAlgue();
    gestionViePoisson();
}

void Aquarium::gestionVieAlgue() {
    std::vector<Algue>::iterator itA, endA;
    std::vector<int> algueVecInt;
    std::vector<Algue> newVecAlgue;
    int implAlgue = 0;
    if(!algues.empty()){
        for(itA = algues.begin(), endA = algues.end(); itA != endA; ++itA) {
            itA->setPv(itA->getPv() + 1);
            itA->setAge(itA->getAge() + 1);
            if(itA->getAge() < 20) {
                newVecAlgue.push_back(algues[implAlgue]);
            } else {
                std::cout << "Une algue est mort de vieillesse" << std::endl;
            }
            implAlgue++;
        }
        this->setAlgues(newVecAlgue);
    }
}

void Aquarium::gestionViePoisson() {
    std::vector<Poisson> newVecPoisson;
    std::vector<Poisson>::iterator itP, endP;
    int implPoisson = 0;
    if(!poissons.empty()){
        for(itP = poissons.begin(), endP = poissons.end(); itP != endP; ++itP) {
            itP->setAge(itP->getAge() + 1);
            if (itP->getAge() < 20) {
                newVecPoisson.push_back(poissons[implPoisson]);
            } else {
                std::cout << itP->getNom() << " est mort de vieillesse" << std::endl;
            }
            implPoisson++;
        }
        this->setPoissons(newVecPoisson);

        newVecPoisson.clear();
        implPoisson = 0;

        for(itP = poissons.begin(), endP = poissons.end(); itP != endP; ++itP) {
            itP->setPv(itP->getPv() - 1);
            if (itP->getPv() > 0) {
                newVecPoisson.push_back(poissons[implPoisson]);
            } else {
                std::cout << itP->getNom() << " est mort" << std::endl;
            }
            implPoisson++;
        }
        this->setPoissons(newVecPoisson);
    }
}

void Aquarium::afficherDetails() {
    std::vector<Algue>::iterator itA, endA;
    std::vector<Poisson>::iterator itP, endP;
    if(!algues.empty()){
        std::cout << "   ------------Algue-------------   " << std::endl;
        /*
        for(itA = algues.begin(), endA = algues.end(); itA != endA; ++itA) {
            std::cout << "PV : " << itA->getPv() << std::endl;
        }*/
        std::cout << "Nombre d'algues : " << algues.size() << std::endl;
    }
    if(!poissons.empty()){
        std::cout << "   ------------Poisson-------------   " << std::endl;
        for(itP = poissons.begin(), endP = poissons.end(); itP != endP; ++itP) {
            std::string val = itP->isHerbivore() ? "Herbivore" : "Carnivore";
            std::cout << "Nom : " << itP->getNom() << "; Sexe : " << itP->getSexe() << "; Race : " << itP->getType() << "; " << val << "; PV : " << itP->getPv() << "; Age : " << itP->getAge() << std::endl;
        }
    }
}

void Aquarium::addAlgue(Algue &a) {
    algues.push_back(a);
}

void Aquarium::reproduction() {
    char genderRandom[] = "MF";
    std::vector<Algue>::iterator itA, endA;
    std::vector<Algue> newAlgues;
    if(!algues.empty()){
        for(itA = algues.begin(), endA = algues.end(); itA != endA; ++itA) {
            if(itA->getPv() >= 10) {
                itA->setPv(itA->getPv()/2);
                auto *a = new Algue();
                a->setPv(a->getPv()/2);
                newAlgues.push_back(*a);
                std::cout << "Une algue a donné naissance à une autre algue" << std::endl;
            }
        }
        for(itA = newAlgues.begin(), endA = newAlgues.end(); itA != endA; ++itA) {
            algues.push_back(*itA);
        }
    }

    std::vector<Poisson>::iterator itP, endP;
    std::vector<Poisson> p = poissons;
    std::vector<Poisson> newVecPoisson;
    if(!poissons.empty()){
        for(itP = poissons.begin(), endP = poissons.end(); itP != endP; ++itP) {
            if(itP->getPv() >= 5) {
                int randIndex = rand() % p.size();
                if(itP->getNom() != p[randIndex].getNom() && itP->getType() == p[randIndex].getType() && itP->getSexe() != p[randIndex].getSexe() && itP->getSexe() == 'M') {
                    auto val = poissons.begin() + randIndex;

                    auto *np = new Poisson(itP->getNom() + "-" + val->getNom() + "_" + "son", genderRandom[rand() % 2], itP->getType());
                    newVecPoisson.push_back(*np);
                    std::cout << itP->getNom() << " et " << val->getNom() << " ont donné naissance à " << np->getNom() << std::endl;
                }
            }
        }
        for(int i = 0; i < newVecPoisson.size(); i++){
            poissons.push_back(newVecPoisson[i]);
        }
    }
}
