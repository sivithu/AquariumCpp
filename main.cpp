#include <iostream>
#include <vector>
#include "Aquarium.h"
#include "Poisson.h"
#include "Algue.h"

void afficherCondition() {
    std::cout << "Tapez sur n pour passer au tour suivant" << std::endl;
    std::cout << "Tapez sur p pour ajouter un poisson dans l'aquarium" << std::endl;
    std::cout << "Tapez sur a pour ajouter une algue dans l'aquarium" << std::endl;
    std::cout << "Tapez sur n'importe quelle touche pour quitter" << std::endl;
}

void chooseFishRace(Poisson *newPoisson){
    int race;

    std::cout << "Choississez une race : " << std::endl;
    std::cout << "\t 1 - MEROU" << std::endl;
    std::cout << "\t 2 - THON" << std::endl;
    std::cout << "\t 3 - POISSON CLOWN" << std::endl;
    std::cout << "\t 4 - SOLE" << std::endl;
    std::cout << "\t 5 - CARPE" << std::endl;
    std::cout << "\t 6 - BAR" << std::endl;

    std::cin >> race;

    switch (race) {
        case 1 :
            newPoisson->setType(Races::MEROU);
            break;
        case 2 :
            newPoisson->setType(Races::THON);
            break;
        case 3 :
            newPoisson->setType(Races::POISSON_CLOWN);
            break;
        case 4 :
            newPoisson->setType(Races::SOLE);
            break;
        case 5 :
            newPoisson->setType(Races::CARPE);
            break;
        case 6 :
            newPoisson->setType(Races::BAR);
            break;
        default :
            std::cout << "Entrée erronée, poisson par défaut : MEROU" << std::endl;
            newPoisson->setType(Races::MEROU);
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
    }
}

void chooseFishName(Poisson *newPoisson) {
    std::string nom;
    std::cin >> nom;
    newPoisson->setNom(nom);
}

void chooseFishGender(Poisson *newPoisson) {
    int genre;
    char genderRandom[] = "MF";

    std::cout << "Choississez un genre" << std::endl;
    std::cout << "1 - Mâle" << std::endl;
    std::cout << "2 - Femelle" << std::endl;

    std::cin >> genre;
    switch (genre) {
        case 1 :
            newPoisson->setSexe('M');
            break;
        case 2 :
            newPoisson->setSexe('F');
            break;
        default:
            newPoisson->setSexe(genderRandom[rand() % 2]);
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
    }
}

void chooseFishAge(Poisson *newPoisson) {
    int age;
    std::cout << "Quel age a " << newPoisson->getNom() << " ?" << std::endl;
    std::cin >> age;
    if(age >= 0 && age < 20) {
        newPoisson->setAge(age);
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } else {
        std::cout << "Entrée erronée, poisson par défaut : 0" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void setupNewFish(Poisson *newPoisson) {
    chooseFishName(newPoisson);
    chooseFishRace(newPoisson);
    chooseFishGender(newPoisson);
    chooseFishAge(newPoisson);
}


int main() {
    std::vector<Poisson> p;
    std::vector<Algue> a;
    /*
    auto *p1 = new Poisson("Faby", 'F', Races::THON);
    p.push_back(*p1);
    auto *p2 = new Poisson("Ramzy", 'M', Races::POISSON_CLOWN);
    p.push_back(*p2);
    auto *p3 = new Poisson("Nass", 'M', Races::CARPE);
    p.push_back(*p3);
    auto *p4 = new Poisson("Vithu", 'M', Races::POISSON_CLOWN);
    p.push_back(*p4);
    auto *a1 = new Algue();
    a.push_back(*a1);
    auto *a2 = new Algue();
    a.push_back(*a2);
    auto *a3 = new Algue();
    a.push_back(*a3);
*/
    Aquarium aquarium = Aquarium(p, a);
    aquarium.passerTour();

    std::string entry;

    afficherCondition();
    std::cin >> entry;

    while (true){
        auto *newPoisson = new Poisson();
        auto *as = new Algue();
        if (entry.empty()) {
            std::cout << "Please enter something" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> entry;
        } else if (entry.size() > 1) {
            std::cout << "Please enter only 1 char" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> entry;
        } else {
            switch (entry[0]) {
                case 'n' :
                    aquarium.passerTour();
                    afficherCondition();
                    std::cin >> entry;
                    break;
                case 'p' :
                    std::cout << "Donnez un nom : ";

                    setupNewFish(newPoisson);
                    aquarium.addPoisson(*newPoisson);
                    afficherCondition();
                    std::cin >> entry;
                    break;
                case 'a' :
                    aquarium.addAlgue(*as);
                    afficherCondition();
                    std::cin >> entry;
                    break;
                case 'q':
                    return 0;
                default:
                    std::cout << "Wrong char" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cin >> entry;
                    break;
            }
        }
    }
}
