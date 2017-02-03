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
        transportShip1 = new TransportShip(12, 16, 10, 100);
        transportShip2 = new TransportShip(100, 200, 90, 1800);
        transportShip3 = new TransportShip(62, 1.4, 60, 120);
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

    ASSERT_EQ(62, transportShip3->getVolume());
    ASSERT_EQ(1.4, transportShip3->getMass());
    ASSERT_EQ(NULL, transportShip3->getLocation());
    ASSERT_EQ(60, transportShip3->getVolumeCapacity());
    ASSERT_EQ(120, transportShip3->getWeightCapacity());
}

TEST_F(TransportShipTest, transport_ship_volume_should_be_greater_than_volume_capacity) {
    ASSERT_GT(transportShip1->getVolume(), transportShip1->getVolumeCapacity());
    ASSERT_GT(transportShip2->getVolume(), transportShip2->getVolumeCapacity());
    ASSERT_GT(transportShip3->getVolume(), transportShip3->getVolumeCapacity());
}

TEST_F(TransportShipTest, transport_ship_load_should_return_false_if_volume_capacity_is_exceeded) {
    Container *container = new Container(50, 10);
    Blaster *blaster = new Blaster(1,1,45);

    ASSERT_FALSE(transportShip1->load(container));
    ASSERT_TRUE(transportShip1->load(blaster));
}

TEST_F(TransportShipTest, transport_ship_load_should_return_false_if_weight_capacity_is_exceeded) {
    Container *container = new Container(50, 1000);
    Blaster *blaster = new Blaster(1,1,45);

    ASSERT_FALSE(transportShip1->load(container));
    ASSERT_TRUE(transportShip1->load(blaster));
}

TEST_F(TransportShipTest, transport_ship_load_should_return_false_if_it_try_to_load_himself) {
    ASSERT_FALSE(transportShip1->load(transportShip1));
}

TEST_F(TransportShipTest, transport_ship_load_should_return_false_if_equipment_already_loaded_elsewhere) {
    Weapon *riffle = new Blaster(1,1,46);

    transportShip3->load(riffle);
    ASSERT_FALSE(transportShip1->load(riffle));
}

TEST_F(TransportShipTest, transport_ship_should_load_equipments_if_they_fit_well) {
    Container *container = new Container(5, 10);
    Blaster *blaster = new Blaster(1, 1, 50);
    Phaser *phaser = new Phaser(1, 1);

    transportShip1->load(blaster);
    transportShip1->load(phaser);

    transportShip2->load(container);

    transportShip3->load(transportShip1);

    ASSERT_GT(transportShip1->getBay().size(), 0);
    ASSERT_EQ(transportShip1->getBay().size(), 2);
    ASSERT_GT(transportShip2->getBay().size(), 0);
    ASSERT_EQ(transportShip2->getBay().size(), 1);
    ASSERT_GT(transportShip3->getBay().size(), 0);
    ASSERT_EQ(transportShip3->getBay().size(), 1);
}

TEST_F(TransportShipTest, transport_ship_mass_should_be_his_own_plus_each_of_load_equipment_mass) {
    double baseMass = transportShip1->getMass();

    Container *container = new Container(10, 16);
    transportShip1->load(container);

    ASSERT_EQ(container->getMass() + baseMass, transportShip1->getMass());

    TransportShip *transportShip = new TransportShip(100, 100, 90, 90);
    baseMass = transportShip->getMass();
    transportShip->load(transportShip1);

    ASSERT_EQ(transportShip1->getMass() + baseMass, transportShip->getMass());
}

TEST_F(TransportShipTest, transport_ship_bay_size_should_decrease_by_1_after_1_uncharging) {
    Container *container = new Container(10, 16);
    transportShip1->load(container);

    ASSERT_EQ(transportShip1->getBay().size(), 1);

    transportShip1->unload(container);
    ASSERT_EQ(transportShip1->getBay().size(), 0);
}

TEST_F(TransportShipTest, transport_ship_can_load_an_equipment_unload_from_an_other_transport_ship) {
    Container *container = new Container(10, 16);
    transportShip1->load(container);

    transportShip1->unload(container);

    ASSERT_TRUE(transportShip2->load(container));
}

TEST_F(TransportShipTest, transport_ship_get_more_weight_and_volume_capacity_after_unloading) {
    Container *container = new Container(10, 16);

    transportShip1->load(container);
    double vcLoaded = transportShip1->getVolumeCapacityRemaining();
    double wcLoaded = transportShip1->getWeightCapacityRemaining();

    transportShip1->unload(container);
    double vcUnloaded = transportShip1->getVolumeCapacityRemaining();
    double wcUnloaded = transportShip1->getWeightCapacityRemaining();

    ASSERT_GT(vcUnloaded, vcLoaded);
    ASSERT_GT(wcUnloaded, wcLoaded);
}

TEST_F(TransportShipTest, transport_ship_can_load_an_equipment_unequipped_from_a_war_ship) {
    // TODO implement when warship will be

}

TEST_F(TransportShipTest, transport_ship_cannot_load_an_equipment_equipped_on_a_war_ship) {
    // TODO implement when warship will be

}