class Solution {
public:
//this problem is same as coin combination from cses
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned long>dp(target+5,0);
        sort(nums.begin(),nums.end());
        int n=nums.size();
        dp[0]=1;
        for(int i=1;i<=target;i++)
        {
            for(int j=0;j<n;j++)
            {   
                if(i>=nums[j])
                {      
                dp[i]=(dp[i]+dp[i-nums[j]]);
                }
            }
        }

        return (int)(dp[target]);
    }
};