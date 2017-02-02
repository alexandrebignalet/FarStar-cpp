#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/Phaser.h"

using testing::Eq;


class PhaserTest : public testing::Test {
public:

    Phaser *phaser;
    PhaserTest() {
        phaser = new Phaser(1,1);
    }
};

TEST_F(PhaserTest, phaser_constructor_test) {
    ASSERT_EQ(1, phaser->getVolume());
    ASSERT_EQ(1, phaser->getMass());
}
