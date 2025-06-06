class Solution {
public:

//just required few tweeks in mcm 
//the problem is basically understanding why this is mcm, this is mcm because we are travelling backwards and not directly (see copy for more info)
int dp[305][305];
int rec(vector<int>& arr,int i,int j)
{
    //base case
    if(i==j)return 0;
    //cache check
    if(dp[i][j]!=-1)return dp[i][j];
    //compute and transition
    int ans=INT_MIN;
    for(int k=i;k<j;k++)
    {
        int tempans= arr[i-1]*arr[k]*arr[j] + rec(arr,i,k) + rec(arr,k+1,j);
        ans=max(ans,tempans);
    }
    return dp[i][j]=ans;
     
}
    int maxCoins(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        vector<int>arr;
        arr.push_back(1);
        for(auto i:nums)
        {
            arr.push_back(i);
        }
        arr.push_back(1);
        return rec(arr, 1, arr.size()-1);


    }   
};