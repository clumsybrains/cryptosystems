#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "ShiftCipher.h"

TEST_CASE("remove spaces all caps")
{
	REQUIRE(remove_spaces_all_caps("This is a test").compare("THISISATEST") == 0);
	REQUIRE(remove_spaces_all_caps("").compare("") == 0);
}

TEST_CASE("Encrypter")
{
	ShiftCipher test;
	REQUIRE((test.encrypt("abcd efg hijk lmnop qrs tuv wx yz", 1)).compare("BCDEFGHIJKLMNOPQRSTUVWXYZA") == 0);
	REQUIRE((test.encrypt("abcd efg hijk lmnop qrs tuv wx yz", 3)).compare("DEFGHIJKLMNOPQRSTUVWXYZABC") == 0);
}