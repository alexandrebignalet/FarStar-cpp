#include "../include/HeavyShip.h"

HeavyShip::HeavyShip(double volume, double mass, int nbMaxArmes): WarShip(volume, mass, nbMaxArmes), Ship(volume, mass) {}