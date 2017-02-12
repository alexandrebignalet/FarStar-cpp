#include "../include/Blaster.h"

int Blaster::nbInstances = 0;

Blaster::Blaster(double volume, double mass, double gazLevel) throw (invalid_argument) : Weapon(volume, mass) {
    if ( gazLevel > 100 || gazLevel < 0 ) {
        throw invalid_argument("Gaz level should be set between 0 and 100");
    } else {
        this->gazLevel = gazLevel;
    }
    this->setName("B-"+ to_string(++Blaster::nbInstances));
}

void Blaster::recharge() {
    this->gazLevel = Blaster::MAX_PERCENT_GAZ_LEVEL;
}

double Blaster::getGazLevel() {
    return this->gazLevel;
}