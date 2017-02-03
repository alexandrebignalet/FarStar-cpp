//
// Created by Alexandre on 01/02/2017.
//

#ifndef FARSTAR_BLASTER_H
#define FARSTAR_BLASTER_H

#include "Weapon.h"

class Blaster: virtual public Weapon {

    static const int MAX_PERCENT_GAZ_LEVEL = 100;

private:

    int gazLevel;

public:

    Blaster(double, double, int);

    void recharge();
    int getGazLevel();

};


#endif //FARSTAR_BLASTER_H