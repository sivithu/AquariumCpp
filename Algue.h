//
// Created by Vithursan Sivakumaran on 02/02/2020.
//

#ifndef AQUARIUM_ALGUE_H
#define AQUARIUM_ALGUE_H

class Algue {
private:
    int pv = 10;
public:
    Algue();

    int getPv() const;
    void setPv(int pv);
};

#endif //AQUARIUM_ALGUE_H
