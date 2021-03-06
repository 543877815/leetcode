int max(int a, int b) {
    return a > b ? a : b;
}

int rob(int *nums, int numsSize) {
    if (numsSize == 0) return 0;
    if (numsSize == 1) return nums[0];
    if (numsSize == 2) return max(nums[0], nums[1]);
    // 去掉最后一个元素
    int *F = (int *) malloc(sizeof(int) * numsSize);
    F[0] = nums[0];
    F[1] = max(nums[0], nums[1]);
    for (int i = 2; i < numsSize - 1; i++) {
        F[i] = max(F[i - 1], F[i - 2] + nums[i]);
    }

    // 去掉首元素
    int *E = (int *) malloc(sizeof(int) * numsSize);
    E[1] = nums[1];
    E[2] = max(nums[1], nums[2]);
    for (int i = 3; i < numsSize; i++) {
        E[i] = max(E[i - 1], E[i - 2] + nums[i]);
    }
    return E[numsSize - 1] > F[numsSize - 2] ? E[numsSize - 1] : F[numsSize - 2];
}

// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int rob(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        // 去掉最后一个元素
        vector<int> F(n);
        F[0] = nums[0];
        F[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n - 1; i++) {
            F[i] = max(F[i - 1], F[i - 2] + nums[i]);
        }

        // 去掉第一个元素
        vector<int> E(n);
        E[1] = nums[1];
        E[2] = max(nums[1], nums[2]);
        for (int i = 3; i < n; i++) {
            E[i] = max(E[i - 1], E[i - 2] + nums[i]);
        }

        return E[n - 1] > F[n - 2] ? E[n - 1] : F[n - 2];
    }
};