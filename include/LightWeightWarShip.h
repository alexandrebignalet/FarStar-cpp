#ifndef FARSTAR_LightWeightWarShip_H
#define FARSTAR_LightWeightWarShip_H


#include "WarShip.h"

class LightWeightWarShip: public WarShip {

public:
    LightWeightWarShip(double volume, double mass, int nbMaxWeapons);

    void load(Equipment* equipement) throw (invalid_argument);
};


#endif //FARSTAR_LightWeightWarShip_H
