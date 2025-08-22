class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int st_row=INT_MAX;
        int end_row=INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    st_row=min(i,st_row);
                    end_row=max(i,end_row);
                }
            }
        }

        int st_col=INT_MAX;
        int end_col=INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    st_col=min(j,st_col);
                    end_col=max(j,end_col);
                }
            }
        }

        //st_row=0;
        //end_row=1;
        //st_col=0;
        //end_col=2;

        return (end_row - st_row + 1)*(end_col - st_col + 1);
        
    }
};