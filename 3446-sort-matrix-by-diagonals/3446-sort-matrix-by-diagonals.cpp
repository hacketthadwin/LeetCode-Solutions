class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>first_diag;
        //start with row-0
        for(int i=0;i<m;i++)
        {
            vector<int>diag;
            for(int j=0;j<n-i;j++)
            {
                diag.push_back(grid[j][i+j]);
            }
            if (i == 0)  
                sort(diag.begin(), diag.end(), greater<int>()); 
            else  
                sort(diag.begin(), diag.end());  
            for(int j=0;j<n-i;j++)
            {
                grid[j][i+j]=diag[j];
            }
        }
        //start with col-0
        for(int i=1;i<n;i++)
        {
            vector<int>diag;
            for(int j=0;j<n-i;j++)
            {
                diag.push_back(grid[i+j][j]);
            }
            sort(diag.begin(),diag.end());
            reverse(diag.begin(),diag.end());
            for(int j=0;j<n-i;j++)
            {
                grid[i+j][j]=diag[j];
            }
        }

        return grid;
     
        
    }
};