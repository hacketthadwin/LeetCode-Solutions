class Solution {
public:

bool check(int a,int n)
{
    if(a>=0 && a<n)return true;
    return false;
}

    bool hasValidPath(vector<vector<int>>& grid) {

        queue<pair<int,int>>q;
        q.push({0,0});

        vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(),-1));

        while(!q.empty())
        {
            int a = q.front().first;
            int b = q.front().second;

            q.pop();

            if(visited[a][b]!=-1)continue;

            visited[a][b]=1;

            if(a==grid.size()-1 && b==grid[0].size()-1)return true;

            if(grid[a][b]==1)
            {
                if(check(b+1,grid[0].size()) && 
                  (grid[a][b+1]==1 || grid[a][b+1]==3 || grid[a][b+1]==5))
                {
                    q.push({a,b+1});
                }

                if(check(b-1,grid[0].size()) && 
                  (grid[a][b-1]==1 || grid[a][b-1]==4 || grid[a][b-1]==6))
                {
                    q.push({a,b-1});
                }
            }

            if(grid[a][b]==2)
            {
                if(check(a-1,grid.size()) && 
                  (grid[a-1][b]==2 || grid[a-1][b]==3 || grid[a-1][b]==4))
                {
                    q.push({a-1,b});
                }

                if(check(a+1,grid.size()) && 
                  (grid[a+1][b]==2 || grid[a+1][b]==5 || grid[a+1][b]==6))
                {
                    q.push({a+1,b});
                }
            }

            if(grid[a][b]==3)
            {
                if(check(b-1,grid[0].size()) && 
                  (grid[a][b-1]==1 || grid[a][b-1]==4 || grid[a][b-1]==6))
                {
                    q.push({a,b-1});
                }

                if(check(a+1,grid.size()) && 
                  (grid[a+1][b]==2 || grid[a+1][b]==5 || grid[a+1][b]==6))
                {
                    q.push({a+1,b});
                }
            }

            if(grid[a][b]==4)
            {
                if(check(b+1,grid[0].size()) && 
                  (grid[a][b+1]==1 || grid[a][b+1]==3 || grid[a][b+1]==5))
                {
                    q.push({a,b+1});
                }

                if(check(a+1,grid.size()) && 
                  (grid[a+1][b]==2 || grid[a+1][b]==5 || grid[a+1][b]==6))
                {
                    q.push({a+1,b});
                }
            }

            if(grid[a][b]==5)
            {
                if(check(b-1,grid[0].size()) && 
                  (grid[a][b-1]==1 || grid[a][b-1]==4 || grid[a][b-1]==6))
                {
                    q.push({a,b-1});
                }

                if(check(a-1,grid.size()) && 
                  (grid[a-1][b]==2 || grid[a-1][b]==3 || grid[a-1][b]==4))
                {
                    q.push({a-1,b});
                }
            }

            if(grid[a][b]==6)
            {
                if(check(b+1,grid[0].size()) && 
                  (grid[a][b+1]==1 || grid[a][b+1]==3 || grid[a][b+1]==5))
                {
                    q.push({a,b+1});
                }

                if(check(a-1,grid.size()) && 
                  (grid[a-1][b]==2 || grid[a-1][b]==3 || grid[a-1][b]==4))
                {
                    q.push({a-1,b});
                }
            }
        }

        return false;
    }
};