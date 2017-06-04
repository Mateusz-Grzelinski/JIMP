//
// Created by mwypych on 01.06.17.
//

#include <gtest/gtest.h>
#include <MemLeakTest.h>
#include <ArabicRomeConsversion.h>

using ::std::literals::string_literals::operator""s;

TEST(ArabicTest, Numbers0to3ToRome){
    ArabicRomeConsversion arab1(1), arab2(2), arab3(3);

    EXPECT_EQ("I", arab1.to_rome());
    EXPECT_EQ("II", arab2.to_rome());
    EXPECT_EQ("III", arab3.to_rome());
}


TEST(ArabicTest, Numbers4to8ToRome){
    size_t inc=4;
    ArabicRomeConsversion arab4(inc), arab5(inc+1), arab8(inc+2);

    EXPECT_EQ("IV", arab4.to_rome());
    EXPECT_EQ("V", arab5.to_rome());
    EXPECT_EQ("VIII", arab8.to_rome());
}


TEST(ArabicTest, Numbers9to13ToRome){
    size_t inc=9;
    ArabicRomeConsversion arab1(inc), arab2(inc+1), arab3(inc+2), arab4(inc+3), arab5(inc+4);

    EXPECT_EQ("IX", arab1.to_rome());
    EXPECT_EQ("X", arab2.to_rome());
    EXPECT_EQ("XI", arab3.to_rome());
    EXPECT_EQ("XII", arab4.to_rome());
    EXPECT_EQ("XIII", arab5.to_rome());
}