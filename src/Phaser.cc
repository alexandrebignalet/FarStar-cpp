//
// Created by Alexandre on 01/02/2017.
//

#include "../include/Phaser.h"

int Phaser::nbInstances = 0;

Phaser::Phaser(double volume, double mass) : Weapon(volume, mass){
    this->setName("P-" + to_string(++Phaser::nbInstances));
}
