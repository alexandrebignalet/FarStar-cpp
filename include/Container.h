//
// Created by Alexandre on 01/02/2017.
//

#ifndef FARSTAR_CONTAINER_H
#define FARSTAR_CONTAINER_H

#include "Equipment.h"

class Container: public Equipment {
public:
    static int nbInstances;
    Container(double, double);
};


#endif //FARSTAR_CONTAINER_H
