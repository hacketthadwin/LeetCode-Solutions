class Solution {
public:
    void solve(vector<vector<char>>& grid) {
        //so this problem asks something else...check every area of O..and if that area does not have any cell on the boundary...then make the whole area as X otherwise leave that area...so what i can do is simply push all the connected component cells into a vector of vector....then will sort every vector in that...and if i get any boundary in that box...then simply...i will reject that vector..idk...may be it can be optimised later but this was my brute force which will get submit ik
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size(),false));
        vector<vector<pair<int,int>>>v;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='O' && !visited[i][j])
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
                                if(m>=0 && m<grid.size() && n>=0 && n<grid[0].size() && grid[m][n]=='O' && !visited[m][n])
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

        vector<vector<pair<int,int>>>last;
        for(int i=0;i<v.size();i++)
        {
            bool is_possible=true;
            for(int j=0;j<v[i].size();j++)
            {
                    int a=v[i][j].first;
                    int b=v[i][j].second;
                    if(a==0 || b==0 || a==grid.size()-1 || b==grid[0].size()-1)
                    {
                        is_possible=false;
                        break;
                    }
            }

            if(is_possible)
            {
                last.push_back(v[i]);
            }
        }

        for(int i=0;i<last.size();i++)
        {
            for(int j=0;j<last[i].size();j++)
            {
                int a=last[i][j].first;
                int b=last[i][j].second;
                grid[a][b]='X';
            }
        }

        
    }
};