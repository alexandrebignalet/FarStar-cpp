#ifndef FARSTAR_SHIP_H
#define FARSTAR_SHIP_H
#include <vector>

#include "Equipment.h"
#include "Weapon.h"

class Ship: public Equipment {

protected:
    vector<Equipment*> equipments;

    Ship(double volume, double mass);

public:
    virtual vector<Equipment*> const &getEquipments() const;
    double getMass();

    virtual void load(Equipment*) = 0 ;
    virtual void unload(Equipment*) = 0;
};


#endif //FARSTAR_SHIP_H
