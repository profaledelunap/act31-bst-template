#define CATCH_CONFIG_MAIN
#include <vector>
using namespace std;
#include "extras.h"
#include "catch.h"
#include "BST.h"

TEST_CASE("testing byLevel", "[byLevel]")
{
  vector<int> output, solution;

  read(output, "output1.txt");
  read(solution, "mysolution1.txt");

  REQUIRE(output == solution);
}