
#ifndef SOLUTION_H
#define SOLUTION_H

#include "node.h"
#include <vector>
#include <queue>
#include <unordered_set>
#include <string>

using namespace std;
namespace sol425
{
    class Solution
    {
    private:
        TrieNode *build(vector<string> &words);
        void _find(vector<string> &words, int row,
                   TrieNode *root, vector<string> &square, vector<vector<string>> &result);

    public:
        vector<vector<string>> find(vector<string> &words);
    };
}
#endif