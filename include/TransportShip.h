//
// Created by alexandre on 2/2/17.
//

#ifndef FARSTAR_TRANSPORTSHIP_H
#define FARSTAR_TRANSPORTSHIP_H

#include "../include/Ship.h"
#include "../include/TransportShip.h"

class TransportShip: virtual public Ship{

private:
    double weightCapacity;
    double volumeCapacity;

public:
    TransportShip(double volume, double mass, double weightCapacity, double volumeCapacity);

    double getWeightCapacity();
    double getVolumeCapacity();
};


#endif //FARSTAR_TRANSPORTSHIP_H
