#include "../include/Ship.h"
#include "../include/TransportShip.h"

Ship::Ship(double volume, double mass) : Equipment(volume, mass){}

vector<Equipment*> const &Ship::getEquipments() const {
    return this->equipments;
}

double Ship::getMass() {
    double totalMass = this->mass;

    for(int unsigned i = 0; i < this->getEquipments().size(); i++){
        totalMass += this->getEquipments()[i]->getMass();
    }

    return totalMass;
}