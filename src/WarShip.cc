#include <netinet/in.h>
#include "../include/WarShip.h"

int WarShip::nbInstances = 0;

WarShip::WarShip(double volume, double mass, int nbMaxWeapons) : Ship(volume, mass) {
    this->nbMaxWeapons = nbMaxWeapons;
    this->name = "VC-"+ to_string(++WarShip::nbInstances);
}

int WarShip::getNbMaxWeapons() {
    return this->nbMaxWeapons;
}
/**
 * Couldn't set the Weapon param type in order to respect contravariance
 * C++ polymorph method param type is also invariant btw
 * @param Weapon *weapon
 */
void WarShip::load(Equipment* equipment) throw (invalid_argument) {
    if ( this->getEquipments().size()+1 > this->nbMaxWeapons ) {
        throw invalid_argument("Impossible to add Weapon. Number maxixum of weapons equipped is reached.");
    }

    if (dynamic_cast<Weapon*>(equipment) == NULL) {
        throw invalid_argument("WarShip can only equip Weapons.");
    }

    Ship::load(equipment);

    dynamic_cast<Weapon*>(equipment)->setEquipped(true);
}

void WarShip::unload(Equipment* equipment) throw (invalid_argument) {
    Ship::unload(equipment);
    dynamic_cast<Weapon*>(equipment)->setEquipped(false);
}