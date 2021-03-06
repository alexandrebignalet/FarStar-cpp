#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/TransportShip.h"
#include "../include/Container.h"
#include "../include/Blaster.h"
#include "../include/Phaser.h"
#include "../include/WarShip.h"
#include "../include/LightWeightWarShip.h"
#include "../include/HeavyWarShip.h"

using testing::Eq;
using testing::Types;
using testing::Test;

class TransportShipTest : public Test {
protected:
    virtual void SetUp() {
        transportShip2 = new TransportShip(100, 200, 90, 1800);
        transportShip3 = new TransportShip(62, 1.4, 60, 120);
        transportShip1 = new TransportShip(12, 16, 10, 100);
    }

    // virtual void TearDown() {}
    TransportShip* transportShip1;
    TransportShip* transportShip2;
    TransportShip* transportShip3;
};

TEST_F(TransportShipTest, transportShip_constructor_test) {
    ASSERT_EQ(10, transportShip1->getVolumeCapacity());
    ASSERT_EQ(100, transportShip1->getWeightCapacity());

    ASSERT_EQ(90, transportShip2->getVolumeCapacity());
    ASSERT_EQ(1800, transportShip2->getWeightCapacity());

    ASSERT_EQ(60, transportShip3->getVolumeCapacity());
    ASSERT_EQ(120, transportShip3->getWeightCapacity());
}

TEST_F(TransportShipTest, transport_ship_cannot_set_his_location_to_warship) {
    WarShip *ws = new WarShip(1,1,1);
    HeavyWarShip *hs = new HeavyWarShip(1,1,1);
    LightWeightWarShip *lws = new LightWeightWarShip(1,1,1);

    ASSERT_THROW(this->transportShip1->setLocation(ws), invalid_argument);
    ASSERT_THROW(this->transportShip1->setLocation(hs), invalid_argument);
    ASSERT_THROW(this->transportShip1->setLocation(lws), invalid_argument);
}

TEST_F(TransportShipTest, transport_ship_volume_must_be_gt_volume_capacity) {
    ASSERT_THROW(new TransportShip(1,1,2,2), invalid_argument);
}

TEST_F(TransportShipTest, transport_ship_load_should_throw_invalid_argument_exception_if_volume_capacity_is_exceeded) {
    Container *container = new Container(50, 10);
    Blaster *blaster = new Blaster(1,1,45);

    ASSERT_THROW(transportShip1->load(container), invalid_argument);

    ASSERT_NO_THROW(transportShip1->load(blaster));
}

TEST_F(TransportShipTest, transport_ship_load_should_throw_invalid_argument_exception_if_weight_capacity_is_exceeded) {
    Container *container = new Container(50, 1000);
    Blaster *blaster = new Blaster(1,1,45);

    ASSERT_THROW(transportShip1->load(container), invalid_argument);

    ASSERT_NO_THROW(transportShip1->load(blaster););
}

TEST_F(TransportShipTest, transport_ship_load_should_throw_invalid_argument_exception_if_it_try_to_load_himself) {
    ASSERT_THROW(transportShip1->load(transportShip1), invalid_argument);
}

TEST_F(TransportShipTest, transport_ship_load_should_throw_invalid_argument_exception_if_equipment_already_loaded_elsewhere) {
    Weapon *riffle = new Blaster(1,1,46);

    transportShip3->load(riffle);

    ASSERT_THROW(transportShip1->load(riffle), invalid_argument);
}

TEST_F(TransportShipTest, transport_ship_should_load_equipments_if_they_fit_well) {
    Container *container = new Container(5, 10);
    Blaster *blaster = new Blaster(1, 1, 50);
    Phaser *phaser = new Phaser(1, 1);

    ASSERT_NO_THROW(transportShip1->load(blaster));
    ASSERT_NO_THROW(transportShip1->load(phaser));

    ASSERT_NO_THROW(transportShip2->load(container));

    ASSERT_NO_THROW(transportShip3->load(transportShip1));

    ASSERT_GT(transportShip1->getEquipments().size(), 0);
    ASSERT_EQ(transportShip1->getEquipments().size(), 2);
    ASSERT_GT(transportShip2->getEquipments().size(), 0);
    ASSERT_EQ(transportShip2->getEquipments().size(), 1);
    ASSERT_GT(transportShip3->getEquipments().size(), 0);
    ASSERT_EQ(transportShip3->getEquipments().size(), 1);
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

    ASSERT_EQ(transportShip1->getEquipments().size(), 1);

    transportShip1->unload(container);
    ASSERT_EQ(transportShip1->getEquipments().size(), 0);
}

TEST_F(TransportShipTest, transport_ship_can_load_an_equipment_unload_from_an_other_transport_ship) {
    Container *container = new Container(10, 16);
    transportShip1->load(container);

    transportShip1->unload(container);

    ASSERT_NO_THROW(transportShip2->load(container));
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

TEST_F(TransportShipTest, transport_ship_should_throw_invalid_argument_exception_if_trying_to_unload_an_equipment_not_loaded) {
    Container *container = new Container(1,1);
    ASSERT_THROW(transportShip1->unload(container), invalid_argument);
}

TEST_F(TransportShipTest, transport_ship_should_loose_some_weight_and_get_some_volume_and_weight_capacity_remaining_after_unloading) {
    Container *container = new Container(1,1);
    transportShip1->load(container);

    double baseWeight = transportShip1->getMass();
    double baseWeightCapRemain = transportShip1->getWeightCapacityRemaining();
    double baseVolumeCapRemain = transportShip1->getVolumeCapacityRemaining();

    transportShip1->unload(container);

    ASSERT_LT(transportShip1->getMass(), baseWeight);
    ASSERT_GT(transportShip1->getWeightCapacityRemaining(), baseWeightCapRemain);
    ASSERT_GT(transportShip1->getVolumeCapacityRemaining(), baseVolumeCapRemain);
}

TEST_F(TransportShipTest, transport_ship_should_get_some_weight_and_loose_some_volume_and_weight_capacity_remaining_after_loading) {
    Container *container = new Container(1,1);

    double baseWeight = transportShip1->getMass();
    double baseWeightCapRemain = transportShip1->getWeightCapacityRemaining();
    double baseVolumeCapRemain = transportShip1->getVolumeCapacityRemaining();

    transportShip1->load(container);

    ASSERT_GT(transportShip1->getMass(), baseWeight);
    ASSERT_LT(transportShip1->getWeightCapacityRemaining(), baseWeightCapRemain);
    ASSERT_LT(transportShip1->getVolumeCapacityRemaining(), baseVolumeCapRemain);
}

TEST_F(TransportShipTest, transport_ship_set_his_location_to_equipment_loaded) {
    Weapon *phaser = new Phaser(1,1);
    Container *container = new Container(1,1);
    Ship *transportShip = new TransportShip(2,2,1,4);

    transportShip1->load(phaser);
    transportShip1->load(container);
    transportShip1->load(transportShip);

    ASSERT_EQ(transportShip1, dynamic_cast<TransportShip*>(phaser->getLocation()));
    ASSERT_EQ(transportShip1, dynamic_cast<TransportShip*>(container->getLocation()));
    ASSERT_EQ(transportShip1, dynamic_cast<TransportShip*>(transportShip->getLocation()));

    ASSERT_EQ((Ship*)transportShip1, phaser->getLocation());
    ASSERT_EQ((Ship*)transportShip1, container->getLocation());
    ASSERT_EQ((Ship*)transportShip1, transportShip->getLocation());
}

TEST_F(TransportShipTest, transport_ship_set_NULL_location_to_equipment_unloaded) {
    Weapon *phaser = new Phaser(1,1);
    Container *container = new Container(1,1);
    Ship *transportShip = new TransportShip(2,2,1,4);

    transportShip1->load(phaser);
    transportShip1->load(container);
    transportShip1->load(transportShip);

    transportShip1->unload(phaser);
    transportShip1->unload(container);
    transportShip1->unload(transportShip);

    ASSERT_EQ(NULL, phaser->getLocation());
    ASSERT_EQ(NULL, container->getLocation());
    ASSERT_EQ(NULL, transportShip->getLocation());
}


TEST_F(TransportShipTest, transport_ship_can_load_an_equipment_unequipped_from_a_war_ship) {
    WarShip *ws = new WarShip(1,1,1);
    Blaster *b = new Blaster(1,1,45);

    EXPECT_NO_THROW(ws->load(b));
    EXPECT_TRUE(b->isEquipped());
    EXPECT_NO_THROW(ws->unload(b));

    ASSERT_NO_THROW(this->transportShip2->load(b));
    ASSERT_EQ(this->transportShip2->getEquipments().size(), 1);
}

TEST_F(TransportShipTest, transport_ship_cannot_load_an_equipment_equipped_on_a_war_ship) {
    WarShip *ws = new WarShip(1,1,1);
    Blaster *b = new Blaster(1,1,45);

    EXPECT_NO_THROW(ws->load(b));
    EXPECT_TRUE(b->isEquipped());

    ASSERT_THROW(this->transportShip2->load(b), invalid_argument);
}