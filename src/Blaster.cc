#include "../include/Blaster.h"

Blaster::Blaster(double volume, double mass, double gazLevel) throw (invalid_argument) : Weapon(volume, mass) {
    if ( gazLevel > 100 || gazLevel < 0 ) {
        throw invalid_argument("gaz level should be set between 0 and 100");
    } else {
        this->gazLevel = gazLevel;
    }
}

void Blaster::recharge() {
    this->gazLevel = Blaster::MAX_PERCENT_GAZ_LEVEL;
}

double Blaster::getGazLevel() {
    return this->gazLevel;
}