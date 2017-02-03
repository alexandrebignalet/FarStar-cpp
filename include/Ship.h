//
// Created by Alexandre on 01/02/2017.
//

#ifndef FARSTAR_SHIP_H
#define FARSTAR_SHIP_H


#include "Equipment.h"

class Ship: public Equipment {

protected:
    Ship(double, double);

    void setLocation(Ship*);
};


#endif //FARSTAR_SHIP_H
