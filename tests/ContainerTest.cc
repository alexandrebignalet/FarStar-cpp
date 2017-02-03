#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/Container.h"

using testing::Eq;
using testing::Types;
using testing::Test;

class ContainerTest : public Test {
protected:
    virtual void SetUp() {
        container1 = new Container(12, 16);
        container2 = new Container(1.001, 12.009);
        container3 = new Container(6.2, 1.4);
    }

    // virtual void TearDown() {}
    Container* container1;
    Container* container2;
    Container* container3;
};

TEST_F(ContainerTest, container_constructor_test) {
    ASSERT_EQ(12, container1->getVolume());
    ASSERT_EQ(16, container1->getMass());
    ASSERT_EQ(NULL, container1->getLocation());

    ASSERT_EQ(1.001, container2->getVolume());
    ASSERT_EQ(12.009, container2->getMass());
    ASSERT_EQ(NULL, container2->getLocation());

    ASSERT_EQ(6.2, container3->getVolume());
    ASSERT_EQ(1.4, container3->getMass());
    ASSERT_EQ(NULL, container3->getLocation());
}
