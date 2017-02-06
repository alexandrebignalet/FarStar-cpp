#include "../include/HeavyWarShip.h"

HeavyWarShip::HeavyWarShip(double volume, double mass, int nbMaxArmes): WarShip(volume, mass, nbMaxArmes), Ship(volume, mass) {}