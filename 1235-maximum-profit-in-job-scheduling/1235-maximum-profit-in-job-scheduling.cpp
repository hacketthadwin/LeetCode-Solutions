class Solution {
public:
int dp[90001];
int solve(vector<tuple<int,int,int>>&v,int index,int n)
{
    //basecase
    if(index==n)return 0;
    //pruning case
    if(index>n)return -1e8;
    //cache check
    if(dp[index]!=-1)return dp[index];
    //compute and transition
    //taken current one
    int findval=lower_bound(v.begin(),v.end(),make_tuple(get<1>(v[index]), 0, 0))-v.begin();
    int c1=get<2>(v[index])+solve(v,findval,n);
    //not taken current one
    int c2=solve(v,index+1,n);
    return dp[index]=max(c1,c2);
}
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<tuple<int,int,int>>v;
        for(int i=0;i<profit.size();i++)
        {
            v.emplace_back(startTime[i],endTime[i],profit[i]);
        }
        sort(v.begin(),v.end());
        memset(dp,-1,sizeof(dp));
        return solve(v,0,(int)profit.size());
    }
};