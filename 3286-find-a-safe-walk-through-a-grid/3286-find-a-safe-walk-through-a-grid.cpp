class Solution {
public:
  bool ispossible = false;
    int m, n;
    int dp[100][100];
    void rec(vector<vector<int>>& grid, int x, int y, int temphealth) {
        if (x < 0 || y < 0 || x >= m || y >= n) return;
        if (temphealth < 1) return;
        if (ispossible) return;
        if (x == m - 1 && y == n - 1) {
            if(grid[x][y]==1)
            {
                if(temphealth>1) ispossible = true;
            }
            else
            {
                ispossible=true;
            }
            return;
        }
        if (dp[x][y] >= temphealth) return;
        dp[x][y] = temphealth;

        rec(grid, x + 1, y, temphealth - (grid[x][y] == 1 ? 1 : 0));
        rec(grid, x, y + 1, temphealth - (grid[x][y] == 1 ? 1 : 0));
        rec(grid, x - 1, y, temphealth - (grid[x][y] == 1 ? 1 : 0));
        rec(grid, x, y - 1, temphealth - (grid[x][y] == 1 ? 1 : 0));
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
         m = grid.size();
        n = grid[0].size();
        memset(dp, -1, sizeof(dp));
        rec(grid, 0, 0, health);
        return ispossible;
        
    }
};