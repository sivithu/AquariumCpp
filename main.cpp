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


int main() {
    std::vector<Poisson> p;
    std::vector<Algue> a;
    /*
    Poisson *p1 = new Poisson("Faby", 'F', Races::THON);
    p.push_back(*p1);
    Poisson *p2 = new Poisson("Ramzy", 'M', Races::POISSON_CLOWN);
    p.push_back(*p2);
    Poisson *p3 = new Poisson("Nass", 'M', Races::CARPE);
    p.push_back(*p3);
    Poisson *p4 = new Poisson("Vithu", 'M', Races::BAR);
    p.push_back(*p4);
    Algue *a1 = new Algue();
    a.push_back(*a1);
    Algue *a2 = new Algue();
    a.push_back(*a2);
    Algue *a3 = new Algue();
    a.push_back(*a3);
     */
    Aquarium aq = Aquarium(p, a);
    aq.passerTour();
    char s1;
    afficherCondition();
    std::cin >> s1;
    while (s1 == 'n'|| s1 == 'a' || s1 == 'p'){
        Poisson *ps = new Poisson();
        Algue *as = new Algue();
        std::string nom;
        switch (s1) {
            case 'n' :
                aq.passerTour();
                afficherCondition();
                std::cin >> s1;
                break;
            case 'p' :
                int genre;
                int race;
                std::cout << "Donnez un nom : ";
                std::cin >> nom;
                ps->setNom(nom);
                std::cout << "Choississez un genre" << std::endl;
                std::cout << "1 - Mâle" << std::endl;
                std::cout << "2 - Femelle" << std::endl;
                std::cin >> genre;
                switch (genre) {
                    case 1 :
                        ps->setSexe('M');
                        break;
                    case 2 :
                        ps->setSexe('F');
                        break;
                    default:
                        ps->setSexe('M');
                        /*
                         * When an error occurs when reading from a stream, an error flag gets set and no more reading is possible
                         * until you clear the error flags. That's why you get an infinite loop.
                         */
                        std::cin.clear();// clears the error flags
                        // this line discards all the input waiting in the stream
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        break;
                }
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
                        ps->setType(Races::MEROU);
                        break;
                    case 2 :
                        ps->setType(Races::THON);
                        break;
                    case 3 :
                        ps->setType(Races::POISSON_CLOWN);
                        break;
                    case 4 :
                        ps->setType(Races::SOLE);
                        break;
                    case 5 :
                        ps->setType(Races::CARPE);
                        break;
                    case 6 :
                        ps->setType(Races::BAR);
                        break;
                    default :
                        std::cout << "Entrée erronée, poisson par défaut : MEROU" << std::endl;
                        ps->setType(Races::MEROU);
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        break;
                }
                aq.addPoission(*ps);
                afficherCondition();
                std::cin >> s1;
                break;
            case 'a' :
                aq.addAlgue(*as);
                afficherCondition();
                std::cin >> s1;
                break;
            default:
                return 0;
        }
    }
    return 0;
}


