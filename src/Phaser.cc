//
// Created by Alexandre on 01/02/2017.
//

#include "../include/Phaser.h"

Phaser::Phaser(double volume, double mass) {
    this->volume = (double)volume;
    this->mass = (double)mass;
    this->location = NULL;
}

Ship* Phaser::getLocation() {
    return this->location;
}

void Phaser::setLocation(Ship* ship) {
    this->location = ship;
}