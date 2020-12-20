
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <stack>
#include <math.h>
#include <queue>
#include <assert.h>
#include <cstring>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool compare(vector<int> &a, vector<int>&b) {
    if (a[1] != b[1]) return a[1] < b[1];
    return a[0] < b[0];
}

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        vector<bool> visited(26, false);
        vector<int> lastIndex(26, -1);
        stack<char> sk;
        for (int i = 0; i < n; i++) {
            lastIndex[s[i] - 'a'] = i;
        }

        for (int i = 0; i < n; i++) {
            if (visited[s[i] - 'a']) continue;
            while (!sk.empty() && sk.top() > s[i] && lastIndex[sk.top() - 'a'] > i) {
                visited[sk.top() - 'a'] = false;
                sk.pop();
            }
            sk.push(s[i]);
            visited[s[i] - 'a'] = true;
        }
        string res;
        while (!sk.empty()) {
            res = sk.top() + res;
            sk.pop();
        }

        return res;
    }
};

int main() {
    auto *solution = new Solution();
    string input ="bcabc";
    solution->removeDuplicateLetters(input);

}

