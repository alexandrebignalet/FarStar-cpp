#include "../include/TransportShip.h"

TransportShip::TransportShip(double volume, double mass, double volumeCapacity, double weightCapacity) : Ship(volume, mass) {
    this->volumeCapacity = volumeCapacity;
    this->weightCapacity = weightCapacity;
}

double TransportShip::getWeightCapacity() {
    return this->weightCapacity;
}
double TransportShip::getVolumeCapacity() {
    return this->volumeCapacity;
}

double TransportShip::getMass(){
    return this->mass; //TODO add all the stuff in the transport ship
}

vector<Equipment*> const &TransportShip::getBay() const{
    return this->bay;
}

bool TransportShip::load(Equipment* equipment) {
    this->bay.push_back(equipment);
}
bool TransportShip::unload(Equipment*){ return true;}