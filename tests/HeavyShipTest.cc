#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/HeavyShip.h"
#include "../include/Phaser.h"
#include "../include/Blaster.h"

using testing::Eq;
using testing::Types;
using testing::Test;

class HeavyShipTest : public Test {
protected:
    virtual void SetUp() {

        heavyShip = new HeavyShip(12, 16, 3);
    }

    // virtual void TearDown() {}
    HeavyShip *heavyShip;
};

TEST_F(HeavyShipTest, like_super_type_heavy_can_equip_any_weapons) {
    Blaster *b = new Blaster(1,1,34);
    Phaser *p = new Phaser(1,1);

    ASSERT_NO_THROW(this->heavyShip->load(b));
    ASSERT_NO_THROW(this->heavyShip->load(p));

    ASSERT_EQ(this->heavyShip->getEquipments().size(), 2);

    ASSERT_TRUE(b->isEquipped());
    ASSERT_TRUE(p->isEquipped());
}