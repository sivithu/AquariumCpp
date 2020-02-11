//
// Created by Vithursan Sivakumaran on 27/01/2020.
//

#ifndef AQUARIUM_AQUARIUM_H
#define AQUARIUM_AQUARIUM_H
#include <string>   // pour std::string
#include <vector>
#include "Poisson.h"
#include "Algue.h"

class Aquarium {
private:
    std::vector<Poisson>poissons;
    std::vector<Algue>algues;
public:
    Aquarium(std::vector<Poisson> poissons, std::vector<Algue> algues);
    ~Aquarium();
    const std::vector<Poisson> &getPoissons() const;
    void setPoissons(const std::vector<Poisson> &poissons);
    const std::vector<Algue> &getAlgues() const;
    void setAlgues(const std::vector<Algue> &algues);
    void passerTour();
    void gestionVie();
    void reproduction();
    void afficherDetails();
    void addPoission(Poisson &p);
    void addAlgue(Algue &a);
};

#endif //AQUARIUM_AQUARIUM_H
