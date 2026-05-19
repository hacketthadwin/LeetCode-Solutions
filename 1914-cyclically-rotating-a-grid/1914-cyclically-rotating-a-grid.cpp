class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        
        //so what my idea is first i will form a vector with all elements from each layer, then i will rotate the elements by whatever k is given, then i will start pushing the elements in their same position in final answer matrix
        
        vector<vector<int>>ans=grid;
        
        for(int i=0;i<(min(m,n))/2;i++)
        {
            vector<int>v;
            
            int top=i;
            int bottom=m-i-1;
            int left=i;
            int right=n-i-1;
            
            //first from left to right
            for(int j=left;j<=right;j++)v.push_back(grid[top][j]);
            
            //then from top to bottom
            for(int j=top+1;j<=bottom-1;j++)v.push_back(grid[j][right]);
            
            //then from right to left
            for(int j=right;j>=left;j--)v.push_back(grid[bottom][j]);
            
            //then from bottom to top
            for(int j=bottom-1;j>=top+1;j--)v.push_back(grid[j][left]);
            
            int sz=v.size();
            int rot=k%sz;
            
            vector<int>temp(sz);
            
            for(int j=0;j<sz;j++)
            {
                temp[j]=v[(j+rot)%sz];
            }
            
            int idx=0;
            
            //first from left to right
            for(int j=left;j<=right;j++)ans[top][j]=temp[idx++];
            
            //then from top to bottom
            for(int j=top+1;j<=bottom-1;j++)ans[j][right]=temp[idx++];
            
            //then from right to left
            for(int j=right;j>=left;j--)ans[bottom][j]=temp[idx++];
            
            //then from bottom to top
            for(int j=bottom-1;j>=top+1;j--)ans[j][left]=temp[idx++];
        }
        
        return ans;
    }
};