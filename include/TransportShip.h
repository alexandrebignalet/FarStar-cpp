//
// Created by alexandre on 2/2/17.
//

#ifndef FARSTAR_TRANSPORTSHIP_H
#define FARSTAR_TRANSPORTSHIP_H

#include "../include/Ship.h"
#include "../include/TransportShip.h"

class TransportShip: public virtual Ship {

protected:
    double weightCapacity;
    double volumeCapacity;
    double weightCapacityRemaining;
    double volumeCapacityRemaining;

public:
    static int nbInstances;
    TransportShip(double volume, double mass, double volumeCapacity, double weightCapacity) throw (invalid_argument);
    double getWeightCapacity();
    double getVolumeCapacity();
    double getWeightCapacityRemaining();
    double getVolumeCapacityRemaining();
    TransportShip* getLocation();
    void setLocation(Ship*) throw (invalid_argument);
    void load(Equipment*) throw (invalid_argument);
    void unload(Equipment*) throw (invalid_argument);
};


#endif //FARSTAR_TRANSPORTSHIP_H
