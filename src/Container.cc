#include "../include/Container.h"

Container::Container(double volume, double mass) : Equipment(volume, mass) {}

void Container::setLocation(Ship* ship) {
    this->location = ship; //TODO add TransportShip cast
}