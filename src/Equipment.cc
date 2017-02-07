#include "../include/Equipment.h"
#include "../include/TransportShip.h"

Equipment::Equipment(double volume, double mass): location(NULL) {
    this->volume = volume;
    this->mass = mass;
}

Ship* Equipment::getLocation() {
    return this->location;
}

void Equipment::setLocation(Ship* ship) {
    this->location = ship;
}

double Equipment::getMass() {
    return this->mass;
}

double Equipment::getVolume() {
    return this->volume;
}

string Equipment::getName() {
    return this->name;
}