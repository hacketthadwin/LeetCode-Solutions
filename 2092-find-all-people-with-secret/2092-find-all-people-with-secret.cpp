class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {

        //initially 0 and firstperson know the secret, now we will start mapping like 0,firstperson, and then firstperson mappings with the time
        vector<vector<pair<int,int>>>adj(n);
        
        for(int i=0;i<meetings.size();i++)
        {
            int a=meetings[i][0];
            int b=meetings[i][1];
            int time=meetings[i][2];
            adj[a].push_back({b,time});
            adj[b].push_back({a,time});
            
        }

        //now we will apply bfs
        queue<pair<int,int>>q;
        q.push({0,0});
        q.push({firstPerson,0});
        vector<int>visited(n,1000000);
        visited[0]=0;
        visited[firstPerson]=0;
        while(!q.empty())
        {
            pair<int,int>node=q.front();
            int a=node.first;
            int time=node.second;
            q.pop();
            for(int i=0;i<adj[a].size();i++)
            {
                pair<int,int> neighbour=adj[a][i];
                int neigh=neighbour.first;
                int neigh_time=neighbour.second;
                if(neigh_time>=time && neigh_time<visited[neigh])
                {
                    visited[neigh]=neigh_time;
                    q.push({neigh,visited[neigh]});
                }
            }
        }

        vector<int>ans;
        for(int i=0;i<visited.size();i++)
        {
            if(visited[i]!=1000000)ans.push_back(i);
        }

        return ans;
        

    }
};