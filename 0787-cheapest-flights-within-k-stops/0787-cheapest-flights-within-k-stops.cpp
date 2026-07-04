class Solution {
public:
vector<vector<int>>dp;
long long rec(int u,vector<vector<pair<int,int>>>&adj,int src, int dst, int k)
{
    //base case
    if(u==dst)
    {
        return 0;
    }
    //pruning case
    if(k==0)return INT_MAX;
    //cache check
    if(dp[u][k]!=-1)return dp[u][k];
    long long cost=INT_MAX;
    for(auto [v,w]:adj[u])
    {
        cost=min(cost,w+rec(v,adj,src,dst,k-1));
    }
    return dp[u][k]=cost;
}
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)
    {
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<flights.size();i++)
        {
            int u=flights[i][0];
            int v=flights[i][1];
            int w=flights[i][2];
            adj[u].push_back({v,w});
        }
        dp.assign(n+5,vector<int>(k+5,-1));
        long long ans=rec(src,adj,src,dst,k+1);
        if(ans>=INT_MAX)return -1;
        return (int)ans;
    }
};