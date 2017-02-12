#include <typeinfo>
#include "../include/Weapon.h"
#include "../include/TransportShip.h"
#include "../include/WarShip.h"

Weapon::Weapon(double volume, double mass) : Equipment(volume, mass){
    this->equipped = false;
}

bool Weapon::isEquipped() {
    return equipped;
}

void Weapon::setEquipped(bool equipped) {
    this->equipped = equipped;
}