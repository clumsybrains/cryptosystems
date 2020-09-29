#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "ShiftCipher.h"

TEST_CASE("remove spaces")
{
	REQUIRE(remove_spaces("This is a test").compare("Thisisatest") == 0);
	REQUIRE(remove_spaces("").compare("") == 0);
}

TEST_CASE("all caps")
{
	REQUIRE(all_caps("This is a test").compare("THIS IS A TEST") == 0);
	REQUIRE(all_caps("").compare("") == 0);
}

TEST_CASE("Shift cipher - encrypter")
{
	ShiftCipher test;
	REQUIRE((test.encrypt("abcd efg hijk lmnop qrs tuv wx yz", 0)).compare("ABCDEFGHIJKLMNOPQRSTUVWXYZ") == 0);
	REQUIRE((test.encrypt("  abcd efg hijklmnop qrstuvwx yz ", 1)).compare("BCDEFGHIJKLMNOPQRSTUVWXYZA") == 0);
	REQUIRE((test.encrypt("ABCD EFG HIJK LMNOP QRS TUV WX YZ", 2)).compare("CDEFGHIJKLMNOPQRSTUVWXYZAB") == 0);
	REQUIRE((test.encrypt("abcd efg hijk lmnop qrs tuv wx yz", 3)).compare("DEFGHIJKLMNOPQRSTUVWXYZABC") == 0);
	REQUIRE((test.encrypt("Abcd efg Hijk Lmnop QrS tuV wx yz", 4)).compare("EFGHIJKLMNOPQRSTUVWXYZABCD") == 0);
	REQUIRE((test.encrypt("abcd efg hijk lmnop qrs tuv wx yz", 5)).compare("FGHIJKLMNOPQRSTUVWXYZABCDE") == 0);
	REQUIRE((test.encrypt("abcd efg hijk lmnop qrs tuv wx yz", 6)).compare("GHIJKLMNOPQRSTUVWXYZABCDEF") == 0);
	REQUIRE((test.encrypt("abcd efg hijk lmnop qrs tuv wx yz", 7)).compare("HIJKLMNOPQRSTUVWXYZABCDEFG") == 0);
	REQUIRE((test.encrypt("abcd efg hijk lmnop qrs tuv wx yz", 8)).compare("IJKLMNOPQRSTUVWXYZABCDEFGH") == 0);
	REQUIRE((test.encrypt("abcd efg hijk lmnop qrs tuv wx yz", 9)).compare("JKLMNOPQRSTUVWXYZABCDEFGHI") == 0);
	REQUIRE((test.encrypt("abcd efg hijk lmnop qrs tuv wx yz", 10)).compare("KLMNOPQRSTUVWXYZABCDEFGHIJ") == 0);
	REQUIRE((test.encrypt("abcd efg hijk lmnop qrs tuv wx yz", 11)).compare("LMNOPQRSTUVWXYZABCDEFGHIJK") == 0);
	REQUIRE((test.encrypt("abcd efg hijk lmnop qrs tuv wx yz", 12)).compare("MNOPQRSTUVWXYZABCDEFGHIJKL") == 0);
	REQUIRE((test.encrypt("abcd efg hijk lmnop qrs tuv wx yz", 13)).compare("NOPQRSTUVWXYZABCDEFGHIJKLM") == 0);
	REQUIRE((test.encrypt("abcd efg hijk lmnop qrs tuv wx yz", 14)).compare("OPQRSTUVWXYZABCDEFGHIJKLMN") == 0);
	REQUIRE((test.encrypt("abcd efg hijk lmnop qrs tuv wx yz", 15)).compare("PQRSTUVWXYZABCDEFGHIJKLMNO") == 0);
	REQUIRE((test.encrypt("abcd efg hijk lmnop qrs tuv wx yz", 16)).compare("QRSTUVWXYZABCDEFGHIJKLMNOP") == 0);
	REQUIRE((test.encrypt("abcd efg hijk lmnop qrs tuv wx yz", 17)).compare("RSTUVWXYZABCDEFGHIJKLMNOPQ") == 0);
	REQUIRE((test.encrypt("abcd efg hijk lmnop qrs tuv wx yz", 18)).compare("STUVWXYZABCDEFGHIJKLMNOPQR") == 0);
	REQUIRE((test.encrypt("abcd efg hijk lmnop qrs tuv wx yz", 19)).compare("TUVWXYZABCDEFGHIJKLMNOPQRS") == 0);
	REQUIRE((test.encrypt("abcd efg hijk lmnop qrs tuv wx yz", 20)).compare("UVWXYZABCDEFGHIJKLMNOPQRST") == 0);
	REQUIRE((test.encrypt("abcd efg hijk lmnop qrs tuv wx yz", 21)).compare("VWXYZABCDEFGHIJKLMNOPQRSTU") == 0);
	REQUIRE((test.encrypt("abcd efg hijk lmnop qrs tuv wx yz", 22)).compare("WXYZABCDEFGHIJKLMNOPQRSTUV") == 0);
	REQUIRE((test.encrypt("abcd efg hijk lmnop qrs tuv wx yz", 23)).compare("XYZABCDEFGHIJKLMNOPQRSTUVW") == 0);
	REQUIRE((test.encrypt("abcd efg hijk lmnop qrs tuv wx yz", 24)).compare("YZABCDEFGHIJKLMNOPQRSTUVWX") == 0);
	REQUIRE((test.encrypt("abcd efg hijk lmnop qrs tuv wx yz", 25)).compare("ZABCDEFGHIJKLMNOPQRSTUVWXY") == 0);
	REQUIRE((test.encrypt("abcd efg hijk lmnop qrs tuv wx yz", 26)).compare("ABCDEFGHIJKLMNOPQRSTUVWXYZ") == 0);
	REQUIRE((test.encrypt("abcd efg hijk lmnop qrs tuv wx yz", 27)).compare("BCDEFGHIJKLMNOPQRSTUVWXYZA") == 0);
	REQUIRE((test.encrypt("abcd efg hijk lmnop qrs tuv wx yz", 28)).compare("CDEFGHIJKLMNOPQRSTUVWXYZAB") == 0);
	REQUIRE((test.encrypt("abcd efg hijk lmnop qrs tuv wx yz", 29)).compare("DEFGHIJKLMNOPQRSTUVWXYZABC") == 0);
	REQUIRE((test.encrypt("abcd efg hijk lmnop qrs tuv wx yz", 30)).compare("EFGHIJKLMNOPQRSTUVWXYZABCD") == 0);
}

TEST_CASE("Caesar cipher - encrypter")
{
	CaesarCipher test;
	REQUIRE((test.encrypt("abcd efg hijk lmnop qrs tuv wx yz")).compare("DEFGHIJKLMNOPQRSTUVWXYZABC") == 0);
	REQUIRE((test.encrypt("  abcd efg hijklmnop qrstuvwx yz ")).compare("DEFGHIJKLMNOPQRSTUVWXYZABC") == 0);
	REQUIRE((test.encrypt("ABCD EFG HIJK LMNOP QRS TUV WX YZ")).compare("DEFGHIJKLMNOPQRSTUVWXYZABC") == 0);
	
}

TEST_CASE("ROT13 cipher")
{
	ROT13 test; 

	REQUIRE((test("abcd efg hijk lmnop qrs tuv wx yz")).compare("NOPQRSTUVWXYZABCDEFGHIJKLM") == 0);
	REQUIRE((test("  abcd efg hijklmnop qrstuvwx yz ")).compare("NOPQRSTUVWXYZABCDEFGHIJKLM") == 0);
	REQUIRE((test("ABCD EFG HIJK LMNOP QRS TUV WX YZ")).compare("NOPQRSTUVWXYZABCDEFGHIJKLM") == 0);

	REQUIRE(test(test("abcdefghijklm")).compare("ABCDEFGHIJKLM") == 0);
	REQUIRE(test(test("nopqrstuvwxyz")).compare("NOPQRSTUVWXYZ") == 0);
}

TEST_CASE("ROT47 cipher")
{
	ROT47 test;
	std::string part_1 = "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNO";
	std::string part_2 = "PQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";

	std::string test_chars = part_1 + part_2;
	std::string result_chars = part_2 + part_1;
	
	REQUIRE((test(test_chars)).compare(result_chars) == 0);
	REQUIRE(test(test(part_1)).compare(part_1) == 0);
	REQUIRE(test(test(part_2)).compare(part_2) == 0);
}
