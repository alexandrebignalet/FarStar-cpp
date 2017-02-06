//
// Created by Alexandre on 01/02/2017.
//

#ifndef FARSTAR_BLASTER_H
#define FARSTAR_BLASTER_H

#include "Weapon.h"

class Blaster: public Weapon {

    static const int MAX_PERCENT_GAZ_LEVEL = 100;

private:

    double gazLevel;

public:

    Blaster(double volume, double mass, double gazLevel) throw (invalid_argument);

    void recharge();
    int getGazLevel();

};


#endif //FARSTAR_BLASTER_H