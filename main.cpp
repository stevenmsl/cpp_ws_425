#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol425;

/*
Input:
["area","lead","wall","lady","ball"]
Output:
[
  [ "wall",
    "area",
    "lead",
    "lady"
  ],
  [ "ball",
    "area",
    "lead",
    "lady"
  ]
]
 ]
*/

tuple<vector<string>, vector<vector<string>>> testFixture1()
{
  auto input = vector<string>{"area", "lead", "wall", "lady", "ball"};
  auto output = vector<vector<string>>{
      {"wall",
       "area",
       "lead",
       "lady"},
      {"ball",
       "area",
       "lead",
       "lady"}};

  return make_tuple(input, output);
}

/*
Input:
["abat","baba","atan","atal"]

Output:
[
  [ "baba",
    "abat",
    "baba",
    "atan"
  ],
  [ "baba",
    "abat",
    "baba",
    "atal"
  ]
]

*/

tuple<vector<string>, vector<vector<string>>> testFixture2()
{
  auto input = vector<string>{"abat", "baba", "atan", "atal"};
  auto output = vector<vector<string>>{
      {"baba",
       "abat",
       "baba",
       "atan"},
      {"baba",
       "abat",
       "baba",
       "atal"}};

  return make_tuple(input, output);
}

void test1()
{
  auto f = testFixture1();
  cout << "Test 1 " << endl;
  cout << "Expect to see " << Util::toString(get<1>(f)) << endl;
  Solution sol;
  cout << Util::toString(sol.find(get<0>(f))) << endl;
}

void test2()
{
  auto f = testFixture2();
  cout << "Test 2 " << endl;
  cout << "Expect to see " << Util::toString(get<1>(f)) << endl;
  Solution sol;
  cout << Util::toString(sol.find(get<0>(f))) << endl;
}
main()
{
  test1();
  test2();
  return 0;
}