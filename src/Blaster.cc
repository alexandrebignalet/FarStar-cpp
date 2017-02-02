//
// Created by Alexandre on 01/02/2017.
//

#include "Blaster.h"

Blaster::Blaster(double volume, double mass, int gazLevel) {
    this->volume = volume;
    this->mass = mass;
    this->location = NULL;
    this->gazLevel = gazLevel;
}

Ship* Blaster::getLocation() {
    return this->location;
}

void Blaster::setLocation(Ship* ship) {
    this->location = ship;
}

void Blaster::recharge() {
    this->gazLevel = Blaster::MAX_PERCENT_GAZ_LEVEL;
}

int Blaster::getGazLevel() {
    return this->gazLevel;
}