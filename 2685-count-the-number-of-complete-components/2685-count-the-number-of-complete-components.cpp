class Solution {
public:
int dfs(int curr,vector<vector<int>>&adj,vector<bool>&visited1)
{
    int cnt=1;
    visited1[curr]=true;
    for(auto v:adj[curr])
    {
        if(!visited1[v])
        {
            cnt+= dfs(v,adj,visited1);
        }
    }
    return cnt;

}
bool dfs2(int curr,vector<vector<int>>&adj,vector<bool>&visited2,int sz)
{
    visited2[curr]=true;
    bool ans=true;
    if((adj[curr].size())!=sz)ans=false;
    for(auto v:adj[curr])
    {
        if(!visited2[v])
        {
            ans&=dfs2(v,adj,visited2,sz);
        }
    }
    return ans;

}
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        //first i will find size of each connected component...then i will find if each node in this is connected to size-1 nodes

        vector<bool>visited1(n,false);
        vector<int>cmp_size;
        for(int i=0;i<n;i++)
        {
            if(!visited1[i])
            {
                int curr_sz=dfs(i,adj,visited1);
                cmp_size.push_back(curr_sz);
            }
        }

        vector<bool>visited2(n,false);
        int ans=0;
        for(int i=0,j=0;i<n;i++)
        {
            if(!visited2[i])
            {
                if(dfs2(i,adj,visited2,cmp_size[j]-1))
                {
                    ans++;
                }
                j++;
            }
        }

        return ans;
    }
};