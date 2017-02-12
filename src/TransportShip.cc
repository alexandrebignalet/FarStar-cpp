#include "../include/TransportShip.h"
#include "../include/WarShip.h"
#include "../include/HybridShip.h"

int TransportShip::nbInstances = 0;

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

    this->setName("VT-" + to_string(++TransportShip::nbInstances));
}

void TransportShip::setLocation(Ship* ship) throw (invalid_argument) {
    if (dynamic_cast<HybridShip*>(ship) != NULL || dynamic_cast<TransportShip*>(ship) != NULL || ship == NULL) {
        Ship::setLocation(ship);
        return;
    }
    throw invalid_argument("TransportShip cannot be located elsewhere than in a TransportShip or an HybridShip.");
}
TransportShip* TransportShip::getLocation() {
    TransportShip* t = dynamic_cast<TransportShip*>(Ship::getLocation());
    HybridShip* hs = dynamic_cast<HybridShip*>(Ship::getLocation());

    if (t != NULL) {
        return t;
    }
    return hs;
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

    if( equipment->getMass() > this->getWeightCapacityRemaining() ) {
        throw std::invalid_argument("Not enough weight capacity remaining to load this equipment.");
    }

    if( equipment->getVolume() > this->getVolumeCapacityRemaining() ) {
        throw std::invalid_argument("Not enough volume capacity remaining to load this equipment.");
    }

    Ship::load(equipment);

    this->weightCapacityRemaining -= equipment->getMass();
    this->volumeCapacityRemaining -= equipment->getVolume();
}

void TransportShip::unload(Equipment* equipment) throw (invalid_argument) {
    Ship::unload(equipment);
    this->weightCapacityRemaining += equipment->getMass();
    this->volumeCapacityRemaining += equipment->getVolume();
}