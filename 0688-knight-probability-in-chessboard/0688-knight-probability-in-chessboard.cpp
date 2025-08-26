class Solution {
public:
double rec(int n, int k,int curr_row,int curr_col,vector<vector<vector<double>>>&dp)
{
        // pruning case
        if (curr_row < 0 || curr_row >= n || curr_col < 0 || curr_col >= n)
            return 0.0;

        // Base case
        if (k == 0)
            return 1.0;

        // Cache check
        if (dp[curr_row][curr_col][k] != -1.0)return dp[curr_row][curr_col][k];


        vector<pair<int,int>> directions = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};

        double ans = 0.0;
        for (auto &d : directions) 
        {
            ans += rec(n, k-1, curr_row + d.first, curr_col + d.second, dp) / 8.0;
        }

        return dp[curr_row][curr_col][k] = ans;
}
    double knightProbability(int n, int k, int row, int column) 
    {
        vector<vector<vector<double>>> dp(n, vector<vector<double>>(n, vector<double>(k+1, -1.0)));
        return rec(n, k, row, column, dp);

    }
};