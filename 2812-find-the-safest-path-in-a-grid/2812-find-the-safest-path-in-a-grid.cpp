class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {

        int n=grid.size();
        int m=grid[0].size();
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        // queue<pair<pair<int,int>,int>>>q; //first two will store the coordinates...next will store the min value till now...if we reach the end through it..then at the end..i will have options to choose the min solution..this is my bfs solution
        // int mini=INT_MAX;
        // q.push_back({{0,0},st_min});
        // vector<vector<bool>>visited(n,vector<int>(m,false));
        // visited[0][0]=true;
        // while(!q.empty())
        // {
        //     int i=q.front().first.first;
        //     int j=q.front().first.second;
        //     int curr_min=q.front().second;

        //     q.pop();
        //     for(int k=0;k<4;k++)
        //     {
        //         int p=i+dx[k];
        //         int q=j+dy[k];
        //         if(p>=0 && p<n && q>=0 && q<m && !visited[p][q])

        //     }

        // }


        //there is one more approach..i can think of which is i first find all distance from the 


        // //now i will apply bfs..and then i will find the minimum distance from every point to every other point
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({i,j});
                    dist[i][j]=0;
                }
            }
        }
        while(!q.empty())
        {
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            //now i will explore cells from this
            for(int k=0;k<4;k++)
            {
                int u=i+dx[k];
                int v=j+dy[k];
                if(u>=0 && u<n && v>=0 && v<m && ((dist[i][j]+abs(u-i)+abs(v-j))<dist[u][v]))
                {
                    q.push({u,v});
                    dist[u][v]=dist[i][j]+abs(u-i)+abs(v-j);
                }
            }
        }
        //now i have dist matrix..now i will just apply bfs in such a way that i get min path from 0,0 to n-1,m-1
        priority_queue<pair<int,pair<int,int>>>pq; //this is different from normal djikstra because in normal djikstra..we find the lowest value path...but here we are told to find the maximum safeness factor
        pq.push({dist[0][0],{0,0}});
        int mini=0;
        vector<vector<int>>min_dist(n,vector<int>(m,0));
        min_dist[0][0]=dist[0][0];
        while(!pq.empty())
        {
            int curr_dist=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();
            if(i==n-1 && j==m-1)
            {
                mini=max(mini,curr_dist);
                continue;
            }
            for(int k=0;k<4;k++)
            {   
                int u=i+dx[k];
                int v=j+dy[k];
                //so there will be a condition which needs to be satisfied..
                if(u>=0 && u<n && v>=0 && v<m && min_dist[u][v]<min(curr_dist,dist[u][v]))
                {
                    pq.push({min(curr_dist,dist[u][v]),{u,v}});
                    min_dist[u][v]=max(min_dist[u][v],min(curr_dist,dist[u][v]));
                }
            }
        }

        return mini;
    }
};