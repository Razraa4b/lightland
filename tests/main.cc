#include <gtest/gtest.h>
#include <gmock/gmock.h>

int main(int argc, char** argv)
{
    testing::InitGoogleTest();
    testing::InitGoogleMock();

    return RUN_ALL_TESTS();
}
