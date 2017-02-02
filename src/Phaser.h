//
// Created by Alexandre on 01/02/2017.
//

#ifndef FARSTAR_PHASER_H
#define FARSTAR_PHASER_H

#include "Weapon.h"

class Phaser: virtual public Weapon {

public:

    Phaser(); // default
    Phaser(const Phaser&); //copie
    Phaser(double, double); //custom
    ~Phaser(); // D'tor

protected:

    Ship* getLocation();
    void setLocation(Ship*);

};


#endif //FARSTAR_PHASER_H