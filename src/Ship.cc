#include "../include/Ship.h"
#include "../include/TransportShip.h"
#include "../include/HybridShip.h"

Ship::Ship(double volume, double mass) : Equipment(volume, mass){}

vector<Equipment*> const &Ship::getEquipments() const {
    return this->equipments;
}

double Ship::getMass() {
    double totalMass = Equipment::getMass();

    for(int unsigned i = 0; i < this->getEquipments().size(); i++){
        totalMass += this->getEquipments()[i]->getMass();
    }

    return totalMass;
}

void Ship::load(Equipment* equipment) throw (invalid_argument) {

    if ( equipment->getLocation() != NULL) {
        throw invalid_argument("Cannot load this equipment because it is already equipped or loaded elsewhere.");
    }

    this->equipments.push_back(equipment);
    equipment->setLocation(this);
}

void Ship::unload(Equipment* equipment) throw (invalid_argument) {
    for(int unsigned i = 0 ; i < this->getEquipments().size() ; i++) {
        if (this->getEquipments()[i] == equipment) {

            this->equipments.erase(this->equipments.begin()+i);
            equipment->setLocation(NULL);
            return;
        }
    }
    throw invalid_argument("Equipment not equipped btw cannot be disequipped.");
}

void Ship::setLocation(Ship* ship) throw (invalid_argument) {
    if (dynamic_cast<HybridShip*>(ship) == NULL && dynamic_cast<TransportShip*>(ship) == NULL && ship != NULL) {
        throw invalid_argument("TransportShip cannot be located elsewhere than in a TransportShip or an HybridShip.");
    }
    Equipment::setLocation(ship);
}