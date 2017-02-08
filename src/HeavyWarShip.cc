#include "../include/HeavyWarShip.h"

HeavyWarShip::HeavyWarShip(double volume, double mass, int nbMaxWeapons): WarShip(volume, mass, nbMaxWeapons), Ship(volume, mass) {}