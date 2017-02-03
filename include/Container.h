//
// Created by Alexandre on 01/02/2017.
//

#ifndef FARSTAR_CONTAINER_H
#define FARSTAR_CONTAINER_H

#include "Equipment.h"

class Container: virtual public Equipment {
public:
    Container(double, double);

protected:
    void setLocation(Ship*);
};


#endif //FARSTAR_CONTAINER_H
