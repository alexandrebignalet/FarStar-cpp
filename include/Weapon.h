//
// Created by Alexandre on 01/02/2017.
//

#ifndef FARSTAR_WEAPON_H
#define FARSTAR_WEAPON_H

#include "Equipment.h"

class Weapon: public Equipment {

protected:
    bool equipped;

    Weapon(double volume, double mass);

public:
    bool isEquipped();
    void setEquipped(bool);
};


#endif //FARSTAR_WEAPON_H
