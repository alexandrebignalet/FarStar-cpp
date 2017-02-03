#include "../include/Equipment.h"

Equipment::Equipment(double volume, double mass) {
    this->volume = volume;
    this->mass = mass;
    this->location = NULL;
}

Ship* Equipment::getLocation() {
    return this->location;
}