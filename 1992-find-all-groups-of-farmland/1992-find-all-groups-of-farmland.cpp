class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& grid) {
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size(),false));
        vector<vector<pair<int,int>>>v;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1 && !visited[i][j])
                {
                        queue<pair<int,int>>q;
                        q.push({i,j});
                        visited[i][j]=true;
                        vector<pair<int,int>>temp;
                        temp.push_back({i,j});
                        while(!q.empty())
                        {
                            int a=q.front().first;
                            int b=q.front().second;
                            q.pop();
                            
                            for(int d=0;d<4;d++)
                            {
                                int m=a+dx[d];
                                int n=b+dy[d];
                                if(m>=0 && m<grid.size() && n>=0 && n<grid[0].size() && grid[m][n]==1 && !visited[m][n])
                                {
                                    q.push({m,n});
                                    temp.push_back({m,n});
                                    visited[m][n]=true;
                                }
                            }
                        }
                        
                        v.push_back(temp);
                }
            }
        }
        vector<vector<int>>ans;
        for(int i=0;i<v.size();i++)
        {
            sort(v[i].begin(),v[i].end());
            int a=v[i][0].first;
            int b=v[i][0].second;
            int c=v[i].back().first;
            int d=v[i].back().second;
            ans.push_back({a,b,c,d});
        }

        return ans;
    }
};