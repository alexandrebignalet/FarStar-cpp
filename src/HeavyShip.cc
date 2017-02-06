//
// Created by alexandre on 2/6/17.
//

#include "../include/HeavyShip.h"

HeavyShip::HeavyShip(double volume, double mass, int nbMaxArmes): WarShip(volume, mass, nbMaxArmes), Ship(volume, mass) {}