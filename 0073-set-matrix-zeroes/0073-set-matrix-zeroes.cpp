class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>>coordinates;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    coordinates.push_back({i,j});
                }
            }
        }
        for(int i=0;i<coordinates.size();i++)
        {
            int a=coordinates[i].first;
            int b=coordinates[i].second;
            for(int j=0;j<matrix.size();j++)
            {
                matrix[j][b]=0;
            }
            for(int j=0;j<matrix[a].size();j++)
            {
                matrix[a][j]=0;
            }
        }
    }
};