//
// Created by alexandre on 2/5/17.
//

#include "../include/LightWeightShip.h"
#include "../include/Phaser.h"

LightWeightShip::LightWeightShip(double volume, double mass, int nbMaxWeapons) : WarShip(volume, mass, nbMaxWeapons), Ship(volume, mass) {}

void LightWeightShip::load(Equipment* equipment) throw (invalid_argument) {
    if (dynamic_cast<Phaser*>(equipment) == NULL) {
        throw invalid_argument("LightWeightShip can only load Phaser Weapon");
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