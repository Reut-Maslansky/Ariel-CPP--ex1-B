#include "doctest.h"
#include "snowman.hpp"
#include <string>

using namespace std;
using namespace ariel;

TEST_CASE("Good snowman: same digits")
{
    CHECK(snowman(11111111) == string("       \n _===_ \n (.,.) \n<( : )>\n ( : ) "));
    CHECK(snowman(22222222) == string("  ___  \n ..... \n\\(o.o)/\n (] [) \n (\" \") "));
    CHECK(snowman(33333333) == string("   _   \n  /_\\  \n (O_O) \n/(> <)\\\n (___) "));
    CHECK(snowman(44444444) == string("  ___  \n (_*_) \n (- -) \n (   ) \n (   ) "));
}

TEST_CASE("Good snowman")
{
    CHECK(snowman(12341234) == string("       \n _===_ \n (O.-)/\n<(> <) \n (   ) "));
    CHECK(snowman(11112222) == string("       \n _===_ \n\\(.,.)/\n (] [) \n (\" \") "));
    CHECK(snowman(21221243) == string("  ___  \n ..... \n (o,o)/\n<(   ) \n (___) "));
    CHECK(snowman(24232422) == string("  ___  \n ..... \n\\(o O) \n (] [) \n (\" \") "));
    CHECK(snowman(33224442) == string("   _   \n  /_\\  \n (o_o) \n (   ) \n (\" \") "));
    CHECK(snowman(34424331) == string("   _   \n  /_\\  \n (- o) \n (> <)\\\n ( : ) "));
    CHECK(snowman(43243211) == string("  ___  \n (_*_) \n (o_-)/\n/( : ) \n ( : ) "));
}

TEST_CASE("Bad snowman: too much digits")
{
    CHECK_THROWS(snowman(123412341234));
    CHECK_THROWS(snowman(111111111));
    CHECK_THROWS(snowman(432213234312));
}

TEST_CASE("Bad snowman: negative number")
{
    CHECK_THROWS(snowman(-23454));
    CHECK_THROWS(snowman(-23232323));
    CHECK_THROWS(snowman(-121));
}

TEST_CASE("Bad snowman: too little digits")
{
    CHECK_THROWS(snowman(1));
    CHECK_THROWS(snowman(2));
    CHECK_THROWS(snowman(3));
    CHECK_THROWS(snowman(1111111));
}

TEST_CASE("Bad snowman: illegal digits")
{
    CHECK_THROWS(snowman(01111111));
    CHECK_THROWS(snowman(10111111));
    CHECK_THROWS(snowman(11011111));
    CHECK_THROWS(snowman(11101111));
    CHECK_THROWS(snowman(11110111));
    CHECK_THROWS(snowman(11111011));
    CHECK_THROWS(snowman(11111101));
    CHECK_THROWS(snowman(11111110));
    CHECK_THROWS(snowman(555));
    CHECK_THROWS(snowman(00000000));
    CHECK_THROWS(snowman(1234230));
}