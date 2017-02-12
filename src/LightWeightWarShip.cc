#include "../include/LightWeightWarShip.h"
#include "../include/Phaser.h"

LightWeightWarShip::LightWeightWarShip(double volume, double mass, int nbMaxWeapons) : WarShip(volume, mass, nbMaxWeapons), Ship(volume, mass) {}

void LightWeightWarShip::load(Equipment* equipment) throw (invalid_argument) {
    if (dynamic_cast<Phaser*>(equipment) == NULL) {
        throw invalid_argument("LightWeightWarShip can only load Phaser Weapon");
    }

    WarShip::load(equipment);
}