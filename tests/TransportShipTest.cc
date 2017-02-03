#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/TransportShip.h"

using testing::Eq;
using testing::Types;
using testing::Test;

class TransportShipTest : public Test {
protected:
    virtual void SetUp() {
        transportShip1 = new TransportShip(12, 16, 100, 100);
        transportShip2 = new TransportShip(100, 200, 90, 180);
        transportShip3 = new TransportShip(6.2, 1.4, 12.23, 16.56);
    }

    // virtual void TearDown() {}
    TransportShip* transportShip1;
    TransportShip* transportShip2;
    TransportShip* transportShip3;
};

TEST_F(TransportShipTest, transportShip_constructor_test) {
    ASSERT_EQ(12, transportShip1->getVolume());
    ASSERT_EQ(16, transportShip1->getMass());
    ASSERT_EQ(NULL, transportShip1->getLocation());

    ASSERT_EQ(1.001, transportShip2->getVolume());
    ASSERT_EQ(12.009, transportShip2->getMass());
    ASSERT_EQ(NULL, transportShip2->getLocation());

    ASSERT_EQ(6.2, transportShip3->getVolume());
    ASSERT_EQ(1.4, transportShip3->getMass());
    ASSERT_EQ(NULL, transportShip3->getLocation());
}
