#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/Phaser.h"
#include "../include/Container.h"
#include "../include/TransportShip.h"

using testing::Eq;
using testing::Types;
using testing::Test;

class EquipmentTest : public Test {
protected:
    virtual void SetUp() {
        phaser1 = new Phaser(1, 1);
        phaser = new Phaser(2.09, 1.43);
        container = new Container(1.001, 12.009);
        transportShip = new TransportShip(6.2, 1.4, 6, 10);
    }

    // virtual void TearDown() {}
    Equipment* phaser;
    Weapon* phaser1;
    Container* container;
    Ship* transportShip;
};

TEST_F(EquipmentTest, equipment_constructor_test) {
    ASSERT_EQ(2.09, phaser->getVolume());
    ASSERT_EQ(1.43, phaser->getMass());
    ASSERT_EQ(NULL, phaser->getLocation());

    ASSERT_EQ(1, phaser1->getVolume());
    ASSERT_EQ(1, phaser1->getMass());
    ASSERT_EQ(NULL, phaser1->getLocation());

    ASSERT_EQ(1.001, container->getVolume());
    ASSERT_EQ(12.009, container->getMass());
    ASSERT_EQ(NULL, container->getLocation());

    ASSERT_EQ(6.2, transportShip->getVolume());
    ASSERT_EQ(1.4, transportShip->getMass());
    ASSERT_EQ(NULL, transportShip->getLocation());
}

TEST_F(EquipmentTest, equipment_can_be_localised_to_null) {
    phaser->setLocation(NULL);
    ASSERT_EQ(NULL, phaser->getLocation());

    phaser1->setLocation(NULL);
    ASSERT_EQ(NULL, phaser1->getLocation());

    container->setLocation(NULL);
    ASSERT_EQ(NULL, container->getLocation());

    transportShip->setLocation(NULL);
    ASSERT_EQ(NULL, transportShip->getLocation());
}