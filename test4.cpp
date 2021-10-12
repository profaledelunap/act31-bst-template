#define CATCH_CONFIG_MAIN
#include <string>
#include "catch.h"
#include "bst.h"

TEST_CASE("testing ancestor", "[ancestor]")
{
	int adding[] = {50, 25, 75, 12, 40, 60, 80, 5, 18, 30, 45, 55, 80};
	BST b3;

	for (int i = 0; i < 13; i++)
	{
		b3.add(adding[i]);
	}

	REQUIRE(b3.getLevel(50) == 0);
	REQUIRE(b3.getLevel(30) == 3);
	REQUIRE(b3.getLevel(80) == 2);
	REQUIRE(b3.getLevel(25) == 1);
}
