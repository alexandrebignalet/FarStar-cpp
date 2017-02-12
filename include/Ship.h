#ifndef FARSTAR_SHIP_H
#define FARSTAR_SHIP_H
#include <vector>

#include "Equipment.h"
#include "Weapon.h"

class Ship: public Equipment {

private:
    vector<Equipment*> equipments;

protected:
    Ship(double volume, double mass);

public:
    virtual vector<Equipment*> const &getEquipments() const;
    double getMass();

    virtual void load(Equipment*)throw (invalid_argument);
    virtual void unload(Equipment*)throw (invalid_argument);
};


#endif //FARSTAR_SHIP_H
