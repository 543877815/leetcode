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

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *createLinkedList(int arr[], int n) {

    if (n == 0)
        return NULL;

    ListNode *head = new ListNode(arr[0]);
    ListNode *curNode = head;
    for (int i = 1; i < n; i++) {
        curNode->next = new ListNode(arr[i]);
        curNode = curNode->next;
    }

    return head;
}

class Solution {
private:
    int reversePairsCore(vector<int> &nums, vector<int> &copy, int start, int end) {
        if (start == end) {
            copy[start] = nums[start];
            return 0;
        }

        int length = (end - start) / 2;

        int left = reversePairsCore(copy, nums, start, start + length);
        int right = reversePairsCore(copy, nums, start + length + 1, end);

        // i 初始化为前半段最后一个数字的下标
        int i = start + length;
        // j 初始化为后半段最后一个数字的下标
        int j = end;
        int indexCopy = end;
        int count = 0;

        while (i >= start && j >= start + length + 1) {
            if (nums[i] > nums[j]) {
                copy[indexCopy--] = nums[i--];
                count += j - start - length;
            } else {
                copy[indexCopy--] = nums[j--];
            }
        }

        for (; i >= start; i--) copy[indexCopy--] = nums[i];
        for (; j >= start + length + 1; j--) copy[indexCopy--] = nums[j];

        return left + right + count;
    }

public:
    int reversePairs(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<int> copy(n);
        for (int i = 0; i < n; i++) copy[i] = nums[i];
        return reversePairsCore(nums, copy, 0, n - 1);
    }
};

int main() {
    vector<int> a = {7,5,6,4};
    Solution solution = Solution();
    solution.reversePairs(a);
}
