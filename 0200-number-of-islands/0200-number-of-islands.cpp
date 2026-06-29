class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size(),false));
        int cnt=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1' && !visited[i][j])
                {
                        cnt++;
                        queue<pair<int,int>>q;
                        q.push({i,j});
                        visited[i][j]=true;
                        while(!q.empty())
                        {
                            int a=q.front().first;
                            int b=q.front().second;
                            q.pop();
                            for(int d=0;d<4;d++)
                            {
                                int m=a+dx[d];
                                int n=b+dy[d];
                                if(m>=0 && m<grid.size() && n>=0 && n<grid[0].size() && grid[m][n]=='1' && !visited[m][n])
                                {
                                    q.push({m,n});
                                    visited[m][n]=true;
                                }
                            }
                        }
                }
            }
        }
        return cnt;
    }
};