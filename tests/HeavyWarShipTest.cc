#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/HeavyWarShip.h"
#include "../include/Phaser.h"
#include "../include/Blaster.h"

using testing::Eq;
using testing::Types;
using testing::Test;

class HeavyWarShipTest : public Test {
protected:
    virtual void SetUp() {

        heavyWarShip = new HeavyWarShip(12, 16, 3);
    }

    // virtual void TearDown() {}
    HeavyWarShip *heavyWarShip;
};

TEST_F(HeavyWarShipTest, like_super_type_heavy_can_equip_any_weapons) {
    Blaster *b = new Blaster(1,1,34);
    Phaser *p = new Phaser(1,1);

    ASSERT_NO_THROW(this->heavyWarShip->load(b));
    ASSERT_NO_THROW(this->heavyWarShip->load(p));

    ASSERT_EQ(this->heavyWarShip->getEquipments().size(), 2);

    ASSERT_TRUE(b->isEquipped());
    ASSERT_TRUE(p->isEquipped());
}