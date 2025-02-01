class Solution {
public:
int dp[10000][2];  //due to states i.e. index and purchased
int solve(vector<int>& nums,int index,int n,bool purchased)
{
    //base case
    if(index>=n)return 0;
    //pruning case
    //covered in basecase
    //cache check
    if(dp[index][purchased]!=-1)return dp[index][purchased];
    int profit=INT_MIN;
    if(purchased)
    {
        int buy=solve(nums,index+1,n,false)-nums[index];
        int not_buy=solve(nums,index+1,n,true);
        profit=max({buy,not_buy,profit});
    }
    else
    {
        int sell=nums[index]+solve(nums,index+2,n,true);
        int not_sell=solve(nums,index+1,n,false);
        profit=max({sell,not_sell,profit});
    }
    return dp[index][purchased]=profit;
}
    int maxProfit(vector<int>& nums) {
                memset(dp,-1,sizeof(dp));
        return solve(nums,0,nums.size(),true);
    }
};