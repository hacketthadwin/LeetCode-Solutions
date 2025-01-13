class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adjlist[n];
        for(int i=0;i<edges.size();i++)
        {
            adjlist[edges[i][0]].push_back(edges[i][1]);
            adjlist[edges[i][1]].push_back(edges[i][0]);
        }
        if (source == destination) return true;
        queue<int>q;
        vector<int>visited(n,0);
        q.push(source);
        visited[source]=1;
        //level not required in this code
        while(!q.empty())
        {
                int curr=q.front();
                q.pop();
                if(curr==destination)return true;
                for(int i=0;i<adjlist[curr].size();i++)
                {
                    int neighbour=adjlist[curr][i];
                    if(visited[neighbour]==0)
                    {

                        q.push(neighbour);
                        visited[neighbour]=1;
                    }
                }
        }

        return false;
    }
};