class Solution {
public:
int dp[400];
int solve(vector<int>& nums,int index,int n)
{
    //base case
    if (index >= n) return 0;
    //cache check
    if(dp[index]!=-1)return dp[index];
    //compute and transition
        int robCurrent = nums[index] + solve(nums, index + 2, n); // Rob current house
        int skipCurrent = solve(nums, index + 1, n);             // Skip current house

    return dp[index]=max(robCurrent, skipCurrent);

}
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,nums.size());
        
    }
};