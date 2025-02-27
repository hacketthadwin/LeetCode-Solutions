class Solution {
public:
void dfs(vector<vector<int>>&adj,vector<int>&cnt,string&label,int u,vector<bool>&visited,vector<int>&ans)
{
    visited[u]=true;
    int before=cnt[label[u]-'a'];
    cnt[label[u]-'a']++;
    for(int i=0;i<adj[u].size();i++)
    {
        int v=adj[u][i];
        if(!visited[v])dfs(adj,cnt,label,v,visited,ans);
    }
    int after= cnt[label[u]-'a'];
    ans[u]=after-before;
}
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>>adj(n);
        vector<int>cnt(26,0);
        vector<int>ans(n);
        vector<bool>visited(n,false);
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(adj,cnt,labels,0,visited,ans);
        return ans;
    }
};