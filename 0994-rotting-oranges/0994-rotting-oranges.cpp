class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size(),false));
    int maxi=0;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            
            if(grid[i][j]==2 && visited[i][j]==false)
            {
                queue<pair<int,int>>q;
                q.push({i,j});
                int curr=0;
                visited[i][j]=true;
                while(!q.empty())
                {

                    bool taken=false;
                   int sz=q.size();
                   while(sz--)
                   {
                        int a=q.front().first;
                        int b=q.front().second;
                        q.pop();
                        for (int k = 0; k < 4; k++) {
                        int ni = a + dx[k];
                        int nj = b + dy[k];
                        if (ni >= 0 && nj >= 0 && ni < n && nj < m && grid[ni][nj] == 1 && visited[ni][nj]==false) {
                            q.push({ni,nj});
                            visited[ni][nj]=true;
                            taken=true;
                        }
                        }

                   }
                    if(taken==true)curr++;
                }
                maxi=max(maxi,curr);


        }
    }
    }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && visited[i][j]==false)
                {
                    return -1;
                }
            }
        }
        return maxi;
    }
};