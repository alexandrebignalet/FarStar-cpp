//
// Created by alexandre on 2/6/17.
//

#include "../include/HybridShip.h"

HybridShip::HybridShip(double volume, double mass, double volumeCapacity, double weightCapacity, int nbMaxWeapons)
        : WarShip(volume, mass, nbMaxWeapons), TransportShip(volume, mass, volumeCapacity, weightCapacity), Ship(volume, mass) {}

void HybridShip::equip(Equipment* equipment) throw (invalid_argument) {
    WarShip::load(equipment);
}

void HybridShip::load(Equipment* equipment) throw (invalid_argument) {
    TransportShip::load(equipment);
}

void HybridShip::unload(Equipment* equipment) throw (invalid_argument) {
    TransportShip::unload(equipment);
}