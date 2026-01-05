class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int mini=INT_MAX;
        long long summer=0;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                summer+=abs(matrix[i][j]);
                if(matrix[i][j]<0)
                {
                    cnt++;
                }
                mini=min(mini,abs(matrix[i][j]));
            }
        }

        if(cnt%2==1)
        {
            summer-=(2*mini);
        }

        return summer;

        
    }
};