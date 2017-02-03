//
// Created by alexandre on 2/2/17.
//

#ifndef FARSTAR_TRANSPORTSHIP_H
#define FARSTAR_TRANSPORTSHIP_H

#include "../include/Ship.h"
#include "../include/TransportShip.h"
#include <vector>

class TransportShip: public Ship {

private:
    vector<Equipment*> bay;
    double weightCapacity;
    double volumeCapacity;
    double weightCapacityRemaining;
    double volumeCapacityRemaining;

public:
    TransportShip(double volume, double mass, double volumeCapacity, double weightCapacity);

    double getWeightCapacity();
    double getVolumeCapacity();
    double getMass();
    vector<Equipment*> const &getBay() const;
    bool load(Equipment*);
    bool unload(Equipment*);
};


#endif //FARSTAR_TRANSPORTSHIP_H
