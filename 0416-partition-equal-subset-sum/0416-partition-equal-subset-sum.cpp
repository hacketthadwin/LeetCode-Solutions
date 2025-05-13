class Solution {
public:
int dp[201][20001];
    int rec(vector<int>& nums, int n, int sum, int currsum) {
        // base case
        if (n == 0) {
            if (currsum == sum - currsum)
                return 0;
            else
                return -1e9;
        }
        //cache check
        if(dp[n][currsum]!=-1)return dp[n][currsum];
        // compute and transition
        if (currsum + nums[n - 1] <= sum - currsum) {
            return dp[n-1][currsum] = max(
                rec(nums, n - 1, sum, currsum + nums[n - 1]),
                rec(nums, n - 1, sum, currsum)
            );
        } else {
            return dp[n-1][currsum] = rec(nums, n - 1, sum, currsum);
        }
    }

    bool canPartition(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int ans2 = rec(nums, nums.size(), sum, 0);
        return ans2 >= 0;
    }
};
