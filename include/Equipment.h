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

public:

    double getMass();
    double getVolume();
    virtual Ship* getLocation() = 0; // makes the class Abstract creating a pure abstract method
    virtual void setLocation(Ship*) = 0;
};


#endif //FARSTAR_EQUIPMENT_H
