class Solution {
public:
//it is compulsory to pass through all empty squares and then come to 2, that is the only valid path to be counted
//else 0;
    int rec(int n,int m,vector<vector<int>>& grid,int rows,int cols,int emptycells)
    {
        if(n<0 || m<0 || n>=rows || m>=cols)return 0;
        if(grid[n][m]==-1)return 0;
        if(grid[n][m]==2)
        {
            if(emptycells==0)return 1;
            return 0;
        }
        int temp = grid[n][m];
        grid[n][m] = -1; // mark visited
        emptycells--;
        int path1=rec(n-1,m,grid,rows,cols,emptycells);
        int path2=rec(n,m-1,grid,rows,cols,emptycells);
        int path3=rec(n,m+1,grid,rows,cols,emptycells);
        int path4=rec(n+1,m,grid,rows,cols,emptycells);
        grid[n][m] = temp; // backtrack
        emptycells++;
        return path1+path2+path3+path4;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        int st_x=-1;
        int st_y=-1;
        int emptycells=0;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(grid[i][j]==0)emptycells++;
                if(grid[i][j]==1)
                {
                    st_x=i;
                    st_y=j;
                }
            }

        }
        emptycells++;
        int ans= rec(st_x,st_y,grid,rows,cols,emptycells);
        return ans;
    }
};