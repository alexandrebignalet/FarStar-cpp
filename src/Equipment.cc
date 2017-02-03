#include "../include/Equipment.h"
#include "../include/TransportShip.h"

Equipment::Equipment(double volume, double mass) {
    this->volume = volume;
    this->mass = mass;
    this->location = NULL;
}

Ship* Equipment::getLocation() {
    return this->location;
}

void Equipment::setLocation(Ship* ship) {
    this->location = (TransportShip*)ship;
}

double Equipment::getMass() {
    return this->mass;
}

double Equipment::getVolume() {
    return this->volume;
}