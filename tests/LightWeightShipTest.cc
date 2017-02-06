#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/LightWeightShip.h"
#include "../include/Phaser.h"
#include "../include/Blaster.h"

using testing::Eq;
using testing::Types;
using testing::Test;

class LightWeightShipTest : public Test {
protected:
    virtual void SetUp() {

        warShip = new WarShip(12, 16, 3);
        lightWeightShip = new LightWeightShip(12, 16, 3);
    }

    // virtual void TearDown() {}
    LightWeightShip *lightWeightShip;
    WarShip *warShip;
};

TEST_F(LightWeightShipTest, light_weight_ship_should_only_load_phasers) {
    Phaser *p = new Phaser(1,1);
    Blaster *b = new Blaster(1,1,56);

    ASSERT_NO_THROW(lightWeightShip->load(p));
    ASSERT_THROW(lightWeightShip->load(b), invalid_argument);
}