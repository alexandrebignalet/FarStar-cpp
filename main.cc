//#include <gtest/gtest.h>
//#include <gmock/gmock.h>
//
//int main(int argc, char* argv[])
//{
//    testing::InitGoogleTest(&argc, argv);
//    RUN_ALL_TESTS();
//    return 0;
//}

#include <iostream>
#include "src/Blaster.h"

using namespace std;


int main()
{
    string hello = "Hello World";

    cout << hello << endl;

    Blaster *b = new Blaster(1, 1, 50);

    cout << b->getLocation() << endl;

    return 0;
}