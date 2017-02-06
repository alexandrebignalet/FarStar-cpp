#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/Blaster.h"

using testing::Eq;
using testing::Types;
using testing::Test;

class BlasterTest : public Test {
protected:
    virtual void SetUp() {
        blaster1 = new Blaster(12, 16, 50);
        blaster2 = new Blaster(1.001, 12.009, 34);
        blaster3 = new Blaster(6.2, 1.4, 67);
    }

    // virtual void TearDown() {}

    Blaster* blaster1;
    Blaster* blaster2;
    Blaster* blaster3;
};

TEST_F(BlasterTest, blaster_constructor_test) {
    ASSERT_EQ(50, blaster1->getGazLevel());

    ASSERT_EQ(34, blaster2->getGazLevel());

    ASSERT_EQ(67, blaster3->getGazLevel());
}

TEST_F(BlasterTest, blaster_can_be_recharge) {
    ASSERT_EQ(50, blaster1->getGazLevel());
    blaster1->recharge();
    ASSERT_EQ(100, blaster1->getGazLevel());

    ASSERT_EQ(34, blaster2->getGazLevel());
    blaster2->recharge();
    ASSERT_EQ(100, blaster2->getGazLevel());
}