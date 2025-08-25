class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> ans;
        ans.reserve(m * n);

        vector<int> ptr(m, 0);

        for (int d = 0; d < m + n - 1; d++) {
            if (d % 2 == 0) 
            {
                int r = min(d, m - 1);
                int c = d - r;
                while (r >= 0 && c < n) 
                {
                    ans.push_back(mat[r][c]);
                    ptr[r] = c + 1;
                    r--;
                    c++;
                }
            } 
            else 
            {

                int c = min(d, n - 1);
                int r = d - c;
                while (r < m && c >= 0) 
                {
                    ans.push_back(mat[r][c]);
                    ptr[r] = c + 1;
                    r++;
                    c--;
                }
            }
        }

        return ans;

    }
};