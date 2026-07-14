class Solution {
public:
int dfs(int curr,vector<vector<pair<int,int>>>&adj,vector<bool>&visited)
{
    visited[curr]=true;
    int ans=INT_MAX;
    for(auto child:adj[curr])
    {
        int v=child.first;
        int w=child.second;
        ans=min(ans,w);
       if(!visited[v]) ans=min(ans,dfs(v,adj,visited));
    }
    return ans;
}
    int minScore(int n, vector<vector<int>>& roads) {
        //score is min value of a path..now i have to find even min of that min....so the lowest possible edge in all paths from 1 to n...
        vector<vector<pair<int,int>>>adj(n+1);
        
        for (auto &road : roads)
        {
            int u = road[0];
            int v = road[1];
            int w = road[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
            
        }

        //i can apply dfs on node 1 and then find the minimum weight of an edge in that dfs
        vector<bool>visited(n+1,false);
        return dfs(1,adj,visited);
        //now i need to find minimum distance of a road between two cities which comes in the path of 1 to n
        //so basically from all path...choose the path with minimum possible score where score is the minimum possible distance between 2 cities
        //yeah this is easy because i can just go to min distance path and then return from it to go to the n...i can just return min_w
    }
};