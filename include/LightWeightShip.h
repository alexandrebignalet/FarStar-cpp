//
// Created by alexandre on 2/5/17.
//

#ifndef FARSTAR_LIGHTWEIGHTSHIP_H
#define FARSTAR_LIGHTWEIGHTSHIP_H


#include "WarShip.h"

class LightWeightShip: public WarShip {

public:
    LightWeightShip(double volume, double mass, int nbMaxWeapons);

    void load(Equipment* equipement) throw (invalid_argument);
};


#endif //FARSTAR_LIGHTWEIGHTSHIP_H
