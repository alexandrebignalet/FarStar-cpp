#include "../include/LightWeightWarShip.h"
#include "../include/Phaser.h"

LightWeightWarShip::LightWeightWarShip(double volume, double mass, int nbMaxWeapons) : WarShip(volume, mass, nbMaxWeapons), Ship(volume, mass) {}

void LightWeightWarShip::load(Equipment* equipment) throw (invalid_argument) {
    if (dynamic_cast<Phaser*>(equipment) == NULL) {
        throw invalid_argument("LightWeightWarShip can only load Phaser Weapon");
    }

    if ( equipment->getLocation() != NULL) {
        throw invalid_argument("Cannot equip this weapon already used equipped or loaded elsewhere.");
    }

    if (dynamic_cast<Weapon*>(equipment) == NULL) {
        throw invalid_argument("WarShip can only equip Weapons.");
    }

    this->equipments.push_back(equipment);
    equipment->setLocation(this);
    dynamic_cast<Weapon*>(equipment)->setEquipped(true);
}