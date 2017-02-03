#include <typeinfo>
#include "../include/Weapon.h"
#include "../include/TransportShip.h"

Weapon::Weapon(double volume, double mass) : Equipment(volume, mass){}

void Weapon::setLocation(Ship* ship) {
    if (this->isEquipped()) {
        this->location = ship; // TODO add WarShip Cast
    } else {
        this->location = (TransportShip*)ship; // TODO add TransportShip Cast -- verify if null can be cast
    }
}

bool Weapon::isEquipped() {

    return this->getLocation() != NULL /* TODO && typeid(this->getLocation())==typeid(Warship)*/;
}