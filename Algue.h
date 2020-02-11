//
// Created by Vithursan Sivakumaran on 02/02/2020.
//

#ifndef AQUARIUM_ALGUE_H
#define AQUARIUM_ALGUE_H

class Algue {
private:
    int pv = 10;
    int age = 0;
public:
    Algue();
    Algue(int age);
    int getPv() const;
    void setPv(int pv);
    int getAge() const;
    void setAge(int age);
};

#endif //AQUARIUM_ALGUE_H
