class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size(),false));
        int cnt=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]>0 && !visited[i][j])
                {
                        int temp_cnt=grid[i][j];
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
                                if(m>=0 && m<grid.size() && n>=0 && n<grid[0].size() && grid[m][n]>0 && !visited[m][n])
                                {
                                    temp_cnt+=grid[m][n];
                                    q.push({m,n});
                                    visited[m][n]=true;
                                }
                            }
                        }

                        cnt=max(temp_cnt,cnt);
                }
            }
        }
        return cnt;
    }
};