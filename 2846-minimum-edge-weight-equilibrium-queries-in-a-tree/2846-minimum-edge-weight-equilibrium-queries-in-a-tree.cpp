class Solution {
public:
int N;
int M;
vector<vector<pair<int,int>>>adj;
vector<int>dep;
vector<vector<vector<pair<int,int>>>>par;

//because adj[parent][curr] is invalid for adjacency list
int getWt(int u,int v)
{
    for(auto x:adj[u])
    {
        if(x.first==v) return x.second;
    }
    return 0;
}

void dfs(int curr,int parent)
{
    dep[curr]=dep[parent]+1;

    int wt=getWt(parent,curr);

    for(int i=1;i<=26;i++)
    {
        par[curr][0][i]={parent,0};
    }

    if(parent!=0)
    {
        par[curr][0][wt]={parent,par[curr][0][wt].second+1};
    }

    //trying to do same thing as my thought process
    for(int i=1;i<M;i++)
    {
        for(int j=1;j<=26;j++)
        {
            par[curr][i][j].first= par[par[curr][i-1][j].first][i-1][j].first;
            par[curr][i][j].second= par[curr][i-1][j].second + par[par[curr][i-1][j].first][i-1][j].second;
        }
    }

    for(auto x:adj[curr])
    {
        if(x.first==parent) continue;
        dfs(x.first,curr);
    }
}

int lca(int u,int v)
{
    if(dep[u]<dep[v]) swap(u,v);

    int diff=dep[u]-dep[v];

    for(int i=M-1;i>=0;i--)
    {
        if((1<<i)<=diff)
        {
            u=par[u][i][1].first;
            diff-=(1<<i);
        }
    }

    if(u==v) return u;

    for(int i=M-1;i>=0;i--)
    {
        if(par[u][i][1].first!=0 && par[u][i][1].first!=par[v][i][1].first)
        {
            u=par[u][i][1].first;
            v=par[v][i][1].first;
        }
    }

    return par[u][0][1].first;
}

vector<int> collect(int node,int ancestor)
{
    vector<int>freq(28,0);
    int diff=dep[node]-dep[ancestor];
    for(int i=M-1;i>=0;i--)
    {
        if((1<<i)<=diff)
        {
            for(int j=1;j<=26;j++)
            {
                freq[j]+=par[node][i][j].second;
            }
            node=par[node][i][1].first;
            diff-=(1<<i);
        }
    }
    return freq;
}

int solve_queries(int a,int b)
{
    int node=lca(a,b);
    vector<int>freq1=collect(a,node);
    vector<int>freq2=collect(b,node);
    vector<int>freq(28,0);
    for(int i=1;i<=26;i++)
    {
        freq[i]=freq1[i]+freq2[i];
    }
    int totalEdges=0;
    int mx=0;
    for(int i=1;i<=26;i++)
    {
        totalEdges+=freq[i];
        mx=max(mx,freq[i]);
    }
    return totalEdges-mx;
}

//now i guess all remaining is solving queries
//but i guess i will need to find lca..so that i can find number of distinct nodes from a to b by first finding number of distinct nodes from a to lca and b to lca..and taking union of them..then finding count of maximumm count of any node..then n-1 will be the minimum number of operations for that pair of nodes which i will need to do
//i guess it will get too lengthy by this
vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
    
    //so as there are only 26 weights..that's the main thing..instead of taking parent as just par[N][M], take it as
    //par[N][M][26]
    //which tells...the parent for each node at 2^th parent and the count of each weight till that
    //nice..most probably this should be the approach...
    //i am taking one based indexing

    N=n;
    M=20;
    adj.resize(n+2);
    dep.resize(n+2);

    par.resize(n+2,vector<vector<pair<int,int>>>(M,vector<pair<int,int>>(28,{0,0})));

    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];
        int w=edges[i][2];

        adj[u+1].push_back({v+1,w});
        adj[v+1].push_back({u+1,w});
    }

    dfs(1,0);

    vector<int>ans;

    for(auto x:queries)
    {
        int a=x[0]+1;
        int b=x[1]+1;

        ans.push_back(solve_queries(a,b));
    }

    return ans;
}
};