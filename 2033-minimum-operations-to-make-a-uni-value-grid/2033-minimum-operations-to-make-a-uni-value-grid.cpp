class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        //2 4 6 8
        //median value i guess is correct answer
        //also if it is impossible to make any value from this
        vector<int>v;
        for(int i=0;i<grid.size();i++) 
        {
            for(int j=0;j<grid[i].size();j++) 
            {
                v.push_back(grid[i][j]);
            }
        }

        sort(v.begin(),v.end());

        int center=v.size()/2;
        int num1=v[center];

        int ops=0;
        for(int i=0;i<v.size();i++) 
        {
            if(abs(v[i]-num1)%x!=0)return -1;
            ops+=abs(v[i]-num1)/x;
        }

        return ops;

    }
};