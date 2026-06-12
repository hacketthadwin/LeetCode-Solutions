class TreeAncestor {
public:
vector<int>dep;
int M;
vector<vector<int>>par;
vector<vector<int>>adj;
    void dfs(int curr,int parent)
    {
       if(parent!=0) dep[curr]=dep[parent]+1;
        par[curr][0]=parent;
        for(int i=1;i<M;i++)
        {
            par[curr][i]=par[par[curr][i-1]][i-1];
        }
        for(auto x:adj[curr])
        {
            if(x!=parent)dfs(x,curr);
        }
    }
//ok so i can adopt 1 trick also...why not 1 based nodes rather than 0
    TreeAncestor(int n, vector<int>& parent) {
        M=30;
        adj.resize(n+10);
        dep.resize(n+10);
        par.resize(n+10,vector<int>(M));
        dep[1]=0;
        //0 is invalid node...nodes start from 1 only
        for(int i=0;i<n;i++)
        {
            adj[parent[i]+1].push_back(i+1);
            adj[i+1].push_back(parent[i]+1);
        }
        dfs(1,0);
    }

    int getKthAncestor(int node, int k) {
        int curr=node+1;
        for(int i=0;i<M;i++)
        {
            if(((k>>i)&1))
            {
                curr=par[curr][i];
            }
        }

        return curr-1;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */