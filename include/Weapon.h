//
// Created by Alexandre on 01/02/2017.
//

#ifndef FARSTAR_WEAPON_H
#define FARSTAR_WEAPON_H

#include "Equipment.h"

class Weapon: public Equipment {

protected:

    Weapon(double, double);

    void setLocation(Ship*);
    bool isEquipped();
};


#endif //FARSTAR_WEAPON_H
