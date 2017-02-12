#include "../include/Container.h"

int Container::nbInstances = 0;

Container::Container(double volume, double mass) : Equipment(volume, mass) {
    this->setName("C-" + to_string(++Container::nbInstances));
}