class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<int>visited(n,false);
        vector<int>comp_size;
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i=0;i<n;i++)
        {
            if(visited[i])continue;
            int cnt=0;
            queue<int>q;
            q.push(i);
            visited[i]=true;
            cnt++;
            while(!q.empty())
            {
                int u=q.front();
                q.pop();
                for(auto v:adj[u])
                {
                    if(!visited[v])
                    {
                        cnt++;
                        q.push(v);
                        visited[v]=true;
                    }
                }
            }

            comp_size.push_back(cnt);
        }

        int total=n;
        long long ans=0;
        for(int i=0;i<comp_size.size();i++)
        {
            int cnt=comp_size[i];
            int curr=n-cnt;
            ans+= (long long)cnt*(curr);
            n-=cnt;
        }
        return ans;
    }
};