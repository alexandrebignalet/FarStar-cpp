#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/LightWeightWarShip.h"
#include "../include/Phaser.h"
#include "../include/Blaster.h"

using testing::Eq;
using testing::Types;
using testing::Test;

class LightWeightWarShipTest : public Test {
protected:
    virtual void SetUp() {

        lightWeightWarShip = new LightWeightWarShip(12, 16, 3);
    }

    // virtual void TearDown() {}
    LightWeightWarShip *lightWeightWarShip;
};

TEST_F(LightWeightWarShipTest, light_weight_ship_should_only_load_phasers) {
    Phaser *p = new Phaser(1,1);
    Blaster *b = new Blaster(1,1,56);

    ASSERT_NO_THROW(this->lightWeightWarShip->load(p));
    ASSERT_THROW(this->lightWeightWarShip->load(b), invalid_argument);
}