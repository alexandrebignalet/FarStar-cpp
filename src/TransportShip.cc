#include "../include/TransportShip.h"
#include <stdexcept>

TransportShip::TransportShip(double volume, double mass, double volumeCapacity, double weightCapacity)
        throw (invalid_argument): Ship(volume, mass)
{
    if (volume <= volumeCapacity) {
        throw std::invalid_argument("Volume capacity and weight capacity must be lower than volume and weight respectively");
    }

    this->volumeCapacity = volumeCapacity;
    this->weightCapacity = weightCapacity;

    this->weightCapacityRemaining = weightCapacity;
    this->volumeCapacityRemaining = volumeCapacity;
}

double TransportShip::getWeightCapacity() {
    return this->weightCapacity;
}
double TransportShip::getVolumeCapacity() {
    return this->volumeCapacity;
}

double TransportShip::getWeightCapacityRemaining() {
    return this->weightCapacityRemaining;
}
double TransportShip::getVolumeCapacityRemaining() {
    return this->volumeCapacityRemaining;
}

void TransportShip::load(Equipment* equipment) throw (invalid_argument) {
    if ( equipment == this ) {
        throw std::invalid_argument("TransportShip cannot load himself.");
    }
    if ( equipment->getLocation() != NULL ) {
        throw std::invalid_argument("Equipment already loaded elsewhere.");
    }

    if( equipment->getMass() > this->getWeightCapacityRemaining() ) {
        throw std::invalid_argument("Not enough weight capacity remaining to load this equipment.");
    }

    if( equipment->getVolume() > this->getVolumeCapacityRemaining() ) {
        throw std::invalid_argument("Not enough volume capacity remaining to load this equipment.");
    }

    this->weightCapacityRemaining -= equipment->getMass();
    this->volumeCapacityRemaining -= equipment->getVolume();

    this->equipments.push_back(equipment);
    equipment->setLocation(this);
}

void TransportShip::unload(Equipment* equipment) throw (invalid_argument) {
    for(int unsigned i = 0 ; i < this->getEquipments().size() ; i++) {
        if (this->getEquipments()[i] == equipment) {

            this->equipments.erase(this->equipments.begin()+i);

            equipment->setLocation(NULL);

            this->weightCapacityRemaining += equipment->getMass();
            this->volumeCapacityRemaining += equipment->getVolume();

            return;
        }
    }

    throw invalid_argument("Equipment not loaded btw cannot be unloaded.");
}