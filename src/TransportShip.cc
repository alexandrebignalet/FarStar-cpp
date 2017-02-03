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

double TransportShip::getMass(){
    double totalMass = this->mass;

    for(int unsigned i = 0; i < this->getBay().size(); i++){
        totalMass += this->getBay()[i]->getMass();
    }

    return totalMass;
}

vector<Equipment*> const &TransportShip::getBay() const{
    return this->bay;
}

bool TransportShip::load(Equipment* equipment) {
    if (
        equipment == this ||
        equipment->getLocation() != NULL ||
        equipment->getMass() > this->getWeightCapacityRemaining() ||
        equipment->getVolume() > this->getVolumeCapacityRemaining()
    ) {
        return false;
    }

    this->weightCapacityRemaining -= equipment->getMass();
    this->volumeCapacityRemaining -= equipment->getVolume();

    this->bay.push_back(equipment);
    equipment->setLocation(this);

    return true;
}

bool TransportShip::unload(Equipment* equipment){
    for(int unsigned i = 0 ; i < this->getBay().size() ; i++) {
        if (this->getBay()[i] == equipment) {

            this->bay.erase(this->bay.begin()+i);

            equipment->setLocation(NULL);

            this->weightCapacityRemaining += equipment->getMass();
            this->volumeCapacityRemaining += equipment->getVolume();

            return true;
        }
    }

    return false;
}
