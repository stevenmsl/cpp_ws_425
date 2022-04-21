#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <set>
#include <cstring>
using namespace sol425;
using namespace std;

/*takeaways
  - build a tire tree so we can search strings
    by prefix quickly
    - the technique used here is to remember
      the indexes of the words that match
      a specific prefix on a node
  - how to find a valid square?
    - start with wall in the first row
      w a l l
    - when choose the second word all we can do is
      to restrict the first char of the second word
      to 'a' - prefix is 'a'
      notice that 'w' won't affect anything
    - let's pick area
      w a l l
      a r e a
    - now how do we decide the third word?
      - for wall the first char has to be a 'l' (word[0][2])
      - for area the second char has to be a 'e' (word[1][2])
      - so we are looking for a word matching the
        prefix 'le'
    - let's pick lead
      w a l l
      a r e a
      l e a d
    - now the fourth word
      - for wall the first char needs to be a 'l' word[0][3]
      - for area the second char needs to be a 'a' word[1][3]
      - for lead the third char needs to be a 'd' word[1][3]
      - so the prefix we are looking for is 'lad'
    - pick lady
      w a l l
      a r e a
      l e a d
      l a d y
    - as you can see when you build the square top-down the
      choice of word becomes more and more restrictive when
      you are determining the next word
*/

vector<vector<string>> Solution::find(vector<string> &words)
{
  auto root = build(words);
  /* nxn sqaure where n = words[0].size() */
  auto sqaure = vector<string>(words[0].size());
  auto result = vector<vector<string>>();

  for (auto w : words)
  {
    /* start with this word as the first row in the square
       to see if we can construct a valid square from here
    */
    sqaure[0] = w;
    _find(words, 1, root, sqaure, result);
  }

  return result;
}

void Solution::_find(vector<string> &words, int row,
                     TrieNode *root, vector<string> &square, vector<vector<string>> &result)
{
  if (row >= words[0].size())
  {
    result.push_back(square);
    return;
  }

  auto prefix = string("");
  /*every word already in the square
    participates in determining
    what the prefix of the next word
    should be
  */
  for (auto i = 0; i < row; i++)
    prefix += square[i][row];

  auto t = root;

  /* find if there is a matching prefix exists
     in the tree
  */
  for (auto i = 0; i < prefix.size(); i++)
  {
    auto indx = prefix[i] - 'a';
    if (!t->children[indx])
      return;
    t = t->children[indx];
  }

  /* try every word that has that matching prefix */
  for (auto indx : t->indexes)
  {
    square[row] = words[indx];
    _find(words, row + 1, root, square, result);
  }
}

TrieNode *Solution::build(vector<string> &words)
{
  auto root = new TrieNode();

  for (auto i = 0; i < words.size(); i++)
  {
    /* for each word starts searching from the root */
    auto t = root;
    for (auto j = 0; j < words[i].size(); j++)
    {
      auto chIndx = words[i][j] - 'a';
      /* extend the prefix */
      if (!t->children[chIndx])
        t->children[chIndx] = new TrieNode();
      t = t->children[chIndx];
      /* record word i matches this prefix */
      t->indexes.push_back(i);
    }
  }

  return root;
}
