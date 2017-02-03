#include "../include/Ship.h"
#include "../include/TransportShip.h"

Ship::Ship(double volume, double mass) : Equipment(volume, mass){}

void Ship::setLocation(Ship* ship) {
    this->location = (TransportShip*) ship;
}