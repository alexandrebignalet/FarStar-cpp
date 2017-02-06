#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/HybridShip.h"
#include "../include/Phaser.h"
#include "../include/Blaster.h"
#include "../include/Container.h"

using testing::Eq;
using testing::Types;
using testing::Test;

class HybridShipTest : public Test {
protected:
    virtual void SetUp() {

        hybridShip = new HybridShip(12, 16, 10, 20, 5);
    }

    // virtual void TearDown() {}
    HybridShip *hybridShip;
};

TEST_F(HybridShipTest, hybrid_ship_should_load_any_equiments) {
    Phaser *p = new Phaser(1,1);
    Container *c = new Container(1,1);
    WarShip *ws = new WarShip(1,1,1);

    ASSERT_NO_THROW(this->hybridShip->load(p));
    ASSERT_NO_THROW(this->hybridShip->load(c));
    ASSERT_NO_THROW(this->hybridShip->load(ws));

    ASSERT_EQ(this->hybridShip->getEquipments().size(), 3);
}

TEST_F(HybridShipTest, hybrid_ship_should_equip_weapons) {
    Phaser *p = new Phaser(1,1);
    Blaster *b = new Blaster(1,1,1);
    Container *c = new Container(1,1);

    ASSERT_NO_THROW(this->hybridShip->equip(p));
    ASSERT_NO_THROW(this->hybridShip->equip(b));

    ASSERT_THROW(this->hybridShip->equip(c), invalid_argument);

    ASSERT_EQ(this->hybridShip->getEquipments().size(), 2);

    ASSERT_TRUE(p->isEquipped());
    ASSERT_TRUE(b->isEquipped());
}

TEST_F(HybridShipTest, hybrid_ship_should_unload_equiments) {
    Phaser *p = new Phaser(1,1);
    Container *c = new Container(1,1);
    WarShip *ws = new WarShip(1,1,1);

    EXPECT_NO_THROW(this->hybridShip->load(p));
    EXPECT_NO_THROW(this->hybridShip->load(c));
    EXPECT_NO_THROW(this->hybridShip->load(ws));

    EXPECT_EQ(this->hybridShip->getEquipments().size(), 3);

    ASSERT_NO_THROW(this->hybridShip->unload(p));
    ASSERT_NO_THROW(this->hybridShip->unload(c));
    ASSERT_NO_THROW(this->hybridShip->unload(ws));

    ASSERT_EQ(this->hybridShip->getEquipments().size(), 0);
}

TEST_F(HybridShipTest, hybrid_ship_should_unequip_weapons) {
    Phaser *p = new Phaser(1,1);
    Blaster *b = new Blaster(1,1,1);

    EXPECT_NO_THROW(this->hybridShip->equip(p));
    EXPECT_NO_THROW(this->hybridShip->equip(b));

    EXPECT_EQ(this->hybridShip->getEquipments().size(), 2);

    EXPECT_TRUE(p->isEquipped());
    EXPECT_TRUE(b->isEquipped());

    ASSERT_NO_THROW(this->hybridShip->unequip(p));
    ASSERT_NO_THROW(this->hybridShip->unequip(b));

    ASSERT_EQ(this->hybridShip->getEquipments().size(), 0);

    ASSERT_FALSE(p->isEquipped());
    ASSERT_FALSE(b->isEquipped());
}