class Solution {
public:
    long long dp[101][101];

    long long solve(vector<vector<int>>& matrix, int row, int col) {
        // Base case
        if (row == matrix.size()) {
            return 0;
        }
        // Pruning case
        if (col < 0 || col >= matrix[0].size()) {
            return 1e8; // Large value to signify an invalid path
        }
        // Cache check
        if (dp[row][col] != -1e7) return dp[row][col];

        // Compute and transition
        long long c1 = matrix[row][col] + solve(matrix, row + 1, col);
        long long c2 = matrix[row][col] + solve(matrix, row + 1, col - 1);
        long long c3 = matrix[row][col] + solve(matrix, row + 1, col + 1);

        return dp[row][col] = min({c1, c2, c3});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
         int n = matrix.size();
        int m = matrix[0].size();
 long long ans = 1e8;
        for (int i = 0; i < 101; i++) {
            for (int j = 0; j < 101; j++) {
                dp[i][j] = -1e7;
            }
        }
    for (int i = 0; i < m; i++) {
            ans = min(ans, solve(matrix, 0, i));
        }
        return (int)ans; // Convert back to int for final result

        
    }
};