class Solution {
public:
vector<vector<int>>adj;
int N;
int M=30;
const long long MOD=1e9+7;
vector<int>dep;
vector<vector<int>>par;
void dfs(int curr,int parent)
{
    if(parent!=-1)dep[curr]=dep[parent]+1;
    par[curr][0]=parent;
    for(int i=1;i<M;i++)
    {
        par[curr][i]=par[par[curr][i-1]][i-1];
    }
    for(auto x:adj[curr])
    {
        if(x!=parent)
        {
            dfs(x,curr);
        }
    }
}
int kth_parent(int curr,int k)
{
    int ans=curr;
    for(int i=0;i<M;i++)
    {
        if((k>>i)&1)
        {
            ans=par[ans][i];
        }
    }
    return ans;
}
int lca(int u,int v)
{
    if(dep[u]<dep[v])swap(u,v);
    int k=dep[u]-dep[v];
    //then lift v
    int new_v=kth_parent(v,k);
    //now all we got to do is find the lca of both u and new_v
    for(int i=0;i<M;i++)
    {
        if(par[u][i]!=par[new_v][i])
        {
            u=par[u][i];
            new_v=par[new_v][i];
        }
    }

    return par[u][0];
}
int dist_between(int u,int v)
{
    return dep[u]+dep[v]-(2*dep[lca(u,v)]);
}

long long binpow(long long a, long long b)
{
    a %= MOD;
    long long res = 1;
    while(b > 0)
    {
        if(b & 1)
            res = (res * a) % MOD;

        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}
    int assignEdgeWeights(vector<vector<int>>& edges) {
        //so basically i just need to find the maximum depth...after that it becomes maths problem...which is number of ways to assign 1 and 2 at n place where n is maximum depth so that we get sum as odd...of course the answer can be very high that's why we get it as modulo 1e9+7
        //if i solve the second version of this problem..this version will automatically gets solved...so basically i will need lca for the second version...i will get lca for the second version...then i will easily find the distance between both nodes...after the node distance...all it is remaining is again maths...first let's figure out the maths for this
        //so what will be the way to count...see i want number of ways get odd..
        //yeah so after observing few test cases..i found out to be just (1<<(n-1)), now i just have to take the modulo of this
        //this can be done in max to max o(log n)..so mathematics done..graph remaining
        N=edges.size()+1;
        dep.resize(N);
        par.resize(N,vector<int>(M));
        adj.resize(N);
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u-1].push_back(v-1);
            adj[v-1].push_back(u-1);
        }
        dep[0]=-1;
        for(int i=0;i<M;i++)
        {
            par[0][i]=0;
        }
        dfs(0,0);
        int maxi=INT_MIN;
        for(int i=0;i<N;i++)
        {
            maxi=max(maxi,dep[i]);
        }
        //maxi is the maximum depth..now i just have to find the (2^(maxi-1))%MOD;
        //easy problem
        return binpow(2,maxi-1);
    }
};