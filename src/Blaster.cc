#include "../include/Blaster.h"

Blaster::Blaster(double volume, double mass, int gazLevel) : Weapon(volume, mass) {
    this->gazLevel = gazLevel;
}

void Blaster::recharge() {
    this->gazLevel = Blaster::MAX_PERCENT_GAZ_LEVEL;
}

int Blaster::getGazLevel() {
    return this->gazLevel;
}