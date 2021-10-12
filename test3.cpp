#define CATCH_CONFIG_MAIN
#include <vector>
using namespace std;
#include "extras.h"
#include "catch.h"
#include "BST.h"

TEST_CASE("testing byLevel", "[byLevel]")
{
  vector<int> output, solution;

  read(output, "test3output.txt");
  read(solution, "mysolution3.txt");

  REQUIRE(output == solution);
}