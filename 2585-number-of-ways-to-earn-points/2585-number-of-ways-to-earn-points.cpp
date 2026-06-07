class Solution {
public:
const int MOD= 1e9 +7;
int dp[55][1005];
int rec(int idx,int target, vector<vector<int>>& types){
    //base case
    if(target==0)return 1;
    if(idx>=types.size())return 0;
    //cache check
    if(dp[idx][target]!=-1)return dp[idx][target];
    //compute and transition
    int count=types[idx][0];
    int marks=types[idx][1];
    int ans=0;
    for(int curr_count=0;curr_count<=count && ((target-(curr_count*marks))>=0);curr_count++)
    {
        if((target-(curr_count*marks))>=0)ans=(ans%MOD+rec(idx+1,(target-(curr_count*marks)),types)%MOD)%MOD;
    }
    return dp[idx][target]=ans;
}
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        memset(dp,-1,sizeof(dp));
        return rec(0,target,types);
    }
};