//
// Created by Vithursan Sivakumaran on 02/02/2020.
//

#include "Algue.h"

int Algue::getPv() const {
    return pv;
}

void Algue::setPv(int number) {
    Algue::pv = number;
}

Algue::Algue() {}

Algue::Algue(int age) : age(age) {}

int Algue::getAge() const {
    return age;
}

void Algue::setAge(int number) {
    Algue::age = number;
}
