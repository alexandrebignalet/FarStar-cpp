#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/WarShip.h"
#include "../include/Phaser.h"
#include "../include/Blaster.h"
#include "../include/TransportShip.h"

using testing::Eq;
using testing::Types;
using testing::Test;

class WarShipTest : public Test {
protected:
    virtual void SetUp() {
        Phaser *p = new Phaser(1,1);

        warShip1 = new WarShip(12, 16, 2);
        warShip2 = new WarShip(100, 200, 3);
        warShip3 = new WarShip(62, 1.4, 6);

        warShip1->load(p);
    }

    // virtual void TearDown() {}
    WarShip* warShip1;
    WarShip* warShip2;
    WarShip* warShip3;
};

TEST_F(WarShipTest, warShip_constructor_test) {
    ASSERT_EQ(warShip1->getNbMaxWeapons(), 2);
    ASSERT_EQ(warShip2->getNbMaxWeapons(), 3);
    ASSERT_EQ(warShip3->getNbMaxWeapons(), 6);
}

TEST_F(WarShipTest, war_ship_load_should_throw_invalid_argument_exception_if_weapon_already_loaded_or_loaded_elsewhere) {
    Phaser *phaser = new Phaser(1,1);
    Blaster *blaster = new Blaster(1,1, 56);
    Phaser *phaser1 = new Phaser(2,2);

    TransportShip *ts = new TransportShip(100,50, 90,100);
    ts->load(phaser);

    ASSERT_THROW(warShip1->load(phaser), invalid_argument);
}

TEST_F(WarShipTest, war_ship_should_load_weapons_if_they_fit_well) {
    Phaser *phaser = new Phaser(2,2);

    ASSERT_NO_THROW(warShip1->load(phaser));
}

TEST_F(WarShipTest, war_ship_loadments_size_should_decrease_by_1_after_1_unload) {
    Blaster *blaster = new Blaster(1,1,45);
    this->warShip2->load(blaster);

    unsigned long initSize = warShip2->getEquipments().size();
    this->warShip2->unload(blaster);

    ASSERT_LT(warShip2->getEquipments().size(), initSize);
}

TEST_F(WarShipTest, war_ship_loadments_size_should_increase_by_1_after_1_load) {
    unsigned long initSize = warShip2->getEquipments().size();
    Blaster *blaster = new Blaster(1,1,45);
    this->warShip2->load(blaster);

    ASSERT_GT(warShip2->getEquipments().size(), initSize);
}

TEST_F(WarShipTest, war_ship_can_load_a_weapon_unload_from_an_other_war_ship) {
    Blaster *b = new Blaster(1,1,45);

    warShip2->load(b);
    warShip2->unload(b);

    ASSERT_NO_THROW(warShip3->load(b));
}

TEST_F(WarShipTest, war_ship_should_throw_invalid_argument_exception_if_trying_to_unload_a_weapon_not_loaded) {
    Blaster *b = new Blaster(1,1,45);

    ASSERT_THROW(warShip2->unload(b), invalid_argument);
}

TEST_F(WarShipTest, war_ship_should_get_some_weight_after_loadpying) {
    double baseMass = warShip2->getMass();

    Blaster *b = new Blaster(1,1,45);

    warShip2->load(b);

    ASSERT_GT(warShip2->getMass(), baseMass);
}

TEST_F(WarShipTest, war_ship_set_his_location_to_weapon_load) {
    Blaster *b = new Blaster(1,1,45);

    this->warShip2->load(b);

    ASSERT_EQ((Ship*)this->warShip2, b->getLocation());
}

TEST_F(WarShipTest, war_ship_set_loaded_at_true_to_weapon_load) {
    Blaster *b = new Blaster(1,1,45);

    this->warShip2->load(b);

    ASSERT_TRUE(b->isEquipped());
}

TEST_F(WarShipTest, war_ship_set_location_at_NULL_to_weapon_unload) {
    Blaster *b = new Blaster(1,1,45);

    this->warShip2->load(b);

    ASSERT_EQ((Ship*)this->warShip2, b->getLocation());

    this->warShip2->unload(b);

//    cout << typeid(dynamic_cast<TransportShip*> (b->getLocation())).name() << endl;
    ASSERT_EQ(NULL, b->getLocation());
}

TEST_F(WarShipTest, war_ship_set_loaded_at_false_to_weapon_unload) {
    Blaster *b = new Blaster(1,1,45);

    this->warShip2->load(b);

    ASSERT_TRUE(b->isEquipped());

    this->warShip2->unload(b);

    ASSERT_FALSE(b->isEquipped());
}