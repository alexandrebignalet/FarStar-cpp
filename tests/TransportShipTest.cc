#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/TransportShip.h"
#include "../include/Container.h"
#include "../include/Blaster.h"
#include "../include/Phaser.h"

using testing::Eq;
using testing::Types;
using testing::Test;

class TransportShipTest : public Test {
protected:
    virtual void SetUp() {
        Container *container = new Container(50, 10);
        TransportShip *ts = new TransportShip(13, 14, 10, 132);
        Blaster *blaster = new Blaster(1, 1, 50);
        Phaser *phaser = new Phaser(1, 1);

        transportShip1 = new TransportShip(12, 16, 10, 100);
        transportShip1->load(blaster);
        transportShip1->load(phaser);

        transportShip2 = new TransportShip(100, 200, 90, 1800);
        transportShip2->load(container);

        transportShip3 = new TransportShip(6.2, 1.4, 6, 12);
        transportShip3->load(ts);
    }

    // virtual void TearDown() {}
    TransportShip* transportShip1;
    TransportShip* transportShip2;
    TransportShip* transportShip3;
};

TEST_F(TransportShipTest, transportShip_constructor_test) {
    ASSERT_EQ(12, transportShip1->getVolume());
    ASSERT_EQ(16, transportShip1->getMass());
    ASSERT_EQ(NULL, transportShip1->getLocation());
    ASSERT_EQ(10, transportShip1->getVolumeCapacity());
    ASSERT_EQ(100, transportShip1->getWeightCapacity());

    ASSERT_EQ(100, transportShip2->getVolume());
    ASSERT_EQ(200, transportShip2->getMass());
    ASSERT_EQ(NULL, transportShip2->getLocation());
    ASSERT_EQ(90, transportShip2->getVolumeCapacity());
    ASSERT_EQ(1800, transportShip2->getWeightCapacity());

    ASSERT_EQ(6.2, transportShip3->getVolume());
    ASSERT_EQ(1.4, transportShip3->getMass());
    ASSERT_EQ(NULL, transportShip3->getLocation());
    ASSERT_EQ(6, transportShip3->getVolumeCapacity());
    ASSERT_EQ(12, transportShip3->getWeightCapacity());
}

TEST_F(TransportShipTest, transport_ship_volume_should_be_greater_than_volume_capacity) {
    ASSERT_GT(transportShip1->getVolume(), transportShip1->getVolumeCapacity());

    ASSERT_GT(transportShip2->getVolume(), transportShip2->getVolumeCapacity());

    ASSERT_GT(transportShip3->getVolume(), transportShip3->getVolumeCapacity());
}

TEST_F(TransportShipTest, transport_ship_should_contains_equipments) {
    ASSERT_GT(transportShip1->getBay().size(), 0);

    ASSERT_GT(transportShip2->getBay().size(), 0);

    ASSERT_GT(transportShip3->getBay().size(), 0);
}