//
// Created by Alexandre on 01/02/2017.
//

#ifndef FARSTAR_EQUIPMENT_H
#define FARSTAR_EQUIPMENT_H

#include <iostream>

class Ship;

using namespace std;

class Equipment {

protected:
    double mass;
    double volume;
    Ship* location;

    Equipment(double volume, double mass);

public:

    virtual void setLocation(Ship*);
    virtual Ship* getLocation();
    virtual double getMass();
    double getVolume();
};


#endif //FARSTAR_EQUIPMENT_H
