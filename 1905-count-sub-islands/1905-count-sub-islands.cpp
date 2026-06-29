class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        vector<vector<bool>>visited2(grid2.size(),vector<bool>(grid2[0].size(),false));
        int cnt=0;
        for(int i=0;i<grid2.size();i++)
        {
            for(int j=0;j<grid2[0].size();j++)
            {
                if(grid2[i][j]==1 && grid1[i][j]==1 && !visited2[i][j] )
                {
                        queue<pair<int,int>>q;
                        q.push({i,j});
                        visited2[i][j]=true;
                        vector<pair<int,int>>temp;
                        temp.push_back({i,j});
                        bool is_possible=true;
                        while(!q.empty())
                        {
                            int a=q.front().first;
                            int b=q.front().second;
                            q.pop();
                            
                            for(int d=0;d<4;d++)
                            {
                                int m=a+dx[d];
                                int n=b+dy[d];
                                if(m>=0 && m<grid2.size() && n>=0 && n<grid2[0].size() && grid2[m][n]==1 && !visited2[m][n])
                                {
                                    if(grid1[m][n]!=1)
                                    {
                                        is_possible=false;
                                    }
                                    q.push({m,n});
                                    temp.push_back({m,n});
                                    visited2[m][n]=true;
                                }
                            }
                        }
                        
                        if(is_possible)cnt++;
                }
            }
        }

     
        return cnt;
        
    }
};