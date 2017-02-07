//
// Created by alexandre on 2/6/17.
//

#ifndef FARSTAR_HYBRIDSHIP_H
#define FARSTAR_HYBRIDSHIP_H


#include "WarShip.h"
#include "TransportShip.h"

//[[deprecated("The actual norm doesn't use those types of ships anymore")]]
class HybridShip: public TransportShip, public WarShip {

public:
    static int nbInstances;
    HybridShip(double volume, double mass, double volumeCapacity, double weightCapacity, int nbMaxWeapons);

    void equip(Equipment*) throw (invalid_argument);
    void unequip(Equipment*) throw (invalid_argument);

    void load(Equipment*) throw (invalid_argument);
    void unload(Equipment*) throw (invalid_argument);
};


#endif //FARSTAR_HYBRIDSHIP_H
