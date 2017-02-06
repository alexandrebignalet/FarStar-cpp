//
// Created by alexandre on 2/5/17.
//

#ifndef FARSTAR_WARSHIP_H
#define FARSTAR_WARSHIP_H


#include "Ship.h"

class WarShip: public virtual Ship {

private:

    int nbMaxWeapons;

public:

    WarShip(double volume, double mass, int nbMaxWeapons);
    int getNbMaxWeapons();
    virtual void load(Equipment*) throw (invalid_argument);
    void unload(Equipment*) throw (invalid_argument);
};


#endif //FARSTAR_WARSHIP_H
