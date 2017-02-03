#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/Phaser.h"

using testing::Eq;
using testing::Types;
using testing::Test;

class PhaserTest : public Test {
protected:
    virtual void SetUp() {
        phaser1 = new Phaser(12, 16);
        phaser2 = new Phaser(1.001, 12.009);
        phaser3 = new Phaser(6.2, 1.4);
    }

    // virtual void TearDown() {}
    Phaser* phaser1;
    Phaser* phaser2;
    Phaser* phaser3;
};

TEST_F(PhaserTest, phaser_constructor_test) {
    ASSERT_EQ(12, phaser1->getVolume());
    ASSERT_EQ(16, phaser1->getMass());
    ASSERT_EQ(NULL, phaser1->getLocation());

    ASSERT_EQ(1.001, phaser2->getVolume());
    ASSERT_EQ(12.009, phaser2->getMass());
    ASSERT_EQ(NULL, phaser2->getLocation());

    ASSERT_EQ(6.2, phaser3->getVolume());
    ASSERT_EQ(1.4, phaser3->getMass());
    ASSERT_EQ(NULL, phaser3->getLocation());
}

TEST_F(PhaserTest, phaser_can_be_localised_to_null) {
    phaser1->setLocation(NULL);
    ASSERT_EQ(NULL, phaser1->getLocation());
}
