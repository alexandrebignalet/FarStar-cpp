#ifndef FARSTAR_BLASTER_H
#define FARSTAR_BLASTER_H

#include "Weapon.h"

class Blaster: public Weapon {

private:

    double gazLevel;
public:
    static const int MAX_PERCENT_GAZ_LEVEL = 100;
    static int nbInstances;

    Blaster(double volume, double mass, double gazLevel) throw (invalid_argument);

    void recharge();
    double getGazLevel();

};


#endif //FARSTAR_BLASTER_H