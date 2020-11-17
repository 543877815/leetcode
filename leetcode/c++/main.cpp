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

class Solution {
private:
    int m, n;
    int dp[4][2] = {
            {1,0},
            {0,1},
            {-1,0},
            {0,-1}
    };
    queue<pair<int, int>> q;
    bool isArea(int x, int y) {
        return x >= 0 && y >= 0 && x < m && y < n;
    }
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> res;
        vector<vector<bool>> visited = vector<vector<bool>>(R, vector<bool>(C, false));
        res.push_back({r0, c0});
        visited[r0][c0] = true;
        m = R;
        n = C;
        q.push({r0, c0});
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int newx = x + dp[i][0];
                int newy = y + dp[i][1];
                if (isArea(newx, newy) && !visited[newx][newy]) {
                    q.push({newx, newy});
                    res.push_back({newx, newy});
                }
            }
        }
        return res;
    }
};

int main() {
    auto *solution = new Solution();
    solution->allCellsDistOrder(2, 3, 1, 2);

}

