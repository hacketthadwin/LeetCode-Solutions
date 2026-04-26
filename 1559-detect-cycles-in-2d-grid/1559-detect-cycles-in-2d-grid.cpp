class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        int dr[4]={1,-1,0,0};
        int dc[4]={0,0,-1,1};
        for(int i=0;i<m;i++)  //checking for every character in the grid
        {
            for(int j=0;j<n;j++)
            {
                if(visited[i][j]) continue;
                queue<pair<pair<int,int>, pair<int,int>>>q;  //yeah cycle checking need parent saving
                q.push({{i,j},{-1,-1}});
                visited[i][j]=true;
                while(!q.empty())
                {
                    int a=q.front().first.first;
                    int b=q.front().first.second;
                    int pr=q.front().second.first;
                    int pc=q.front().second.second;
                    q.pop();
                    for(int k=0;k<4;k++)
                    {
                        int nr=a+dr[k];
                        int nc=b+dc[k];
                        if(nr>=0 && nc>=0 && nr<m && nc<n && grid[a][b]==grid[nr][nc])
                        {
                            if(!visited[nr][nc])
                            {
                                visited[nr][nc]=true;
                                q.push({{nr,nc},{a,b}});
                            }
                            else if(nr!=pr || nc!=pc)
                            {
                                return true;
                            }
                        }
                    }
                }
            }
        }
        return false;
    }
};