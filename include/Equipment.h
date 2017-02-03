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

    Equipment(double, double);
    virtual void setLocation(Ship*) = 0;

public:

    double getMass();
    double getVolume();
    Ship* getLocation();

};


#endif //FARSTAR_EQUIPMENT_H
