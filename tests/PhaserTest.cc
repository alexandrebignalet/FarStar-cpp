#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/Phaser.h"

using testing::Eq;

namespace {
    class ClassDeclaration : public testing::Test {
        public:
        Phaser phaser;
        ClassDeclaration() {
            phaser;
        }
    };
}

TEST_F(ClassDeclaration, nameOfTheTest1) {
    ASSERT_EQ("","");
}

TEST_F(ClassDeclaration, nameOfTheTest2) {
    ASSERT_EQ("", "");
}
