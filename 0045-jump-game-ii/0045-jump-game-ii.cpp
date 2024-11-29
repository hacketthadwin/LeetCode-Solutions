class Solution {
public:
  int dp[10010];
    int rec(vector<int>& nums, int currind) {
        if (currind >= nums.size() - 1) return 0;
        if (dp[currind] != -1) return dp[currind];

        int minSteps = INT_MAX;
        for (int i = 1; i <= nums[currind]; i++) 
        {
            int nextIndex = currind + i;
            if (nextIndex < nums.size()) 
            {
                int steps = rec(nums, nextIndex);
                if (steps != INT_MAX) //got some solution
                { 
                    minSteps = min(minSteps, 1 + steps);   
                }
            }
        }
        return dp[currind] = minSteps;
    }

    int jump(vector<int>& nums) {
        memset(dp, -1, sizeof(dp)); 
        return rec(nums, 0);  
    }
};