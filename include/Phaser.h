//
// Created by Alexandre on 01/02/2017.
//

#ifndef FARSTAR_PHASER_H
#define FARSTAR_PHASER_H

#include "Weapon.h"

class Phaser: public Weapon {

public:
    static int nbInstances;
    Phaser(double, double);
};


#endif //FARSTAR_PHASER_H