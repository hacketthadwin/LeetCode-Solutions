class Solution {
public:
//the mistake i made in this is
// 1. always check the condition cnt>0 in every for loop (don't think your loop variables are enough to handle it)
// 2. for a and b, i took index, but for c and d, i took size (m and n)
// therefore, i will need to take index of c and d also i.e. d-1 and c-1 wherever required
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int cnt=(m*n);
        int a=0,b=0,c=m,d=n;  //a denotes the starting index of one row i.e. arr[a][---]
        vector<int>ans;
        while(cnt>0)
        {
            //first we will go from left to right, ok
            //so for that, we have one thing constant which is value of b
            for(int i=b;i<d && cnt>0;i++)
            {
                ans.push_back(matrix[a][i]);
                cnt--;
            }
            a++;
            for(int i=a;i<c && cnt>0;i++)
            {
                ans.push_back(matrix[i][d-1]);
                cnt--;
            }
            d--;
            for(int i=d-1;i>=b && cnt>0;i--)
            {
                ans.push_back(matrix[c-1][i]);
                cnt--;
            }
            c--;
            for(int i=c-1;i>=a && cnt>0;i--)
            {
                ans.push_back(matrix[i][b]);
                cnt--;
            }
            b++;
        }
        return ans;
    }
};