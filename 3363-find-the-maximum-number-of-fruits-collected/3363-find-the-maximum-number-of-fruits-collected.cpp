class Solution {
public:
//ok so my dp state will be like dp[i][j] where i is the row index and j is column index
//i am starting at n-1,0 or 0,n-1
//let's suppose i am currently at i,j, i can visit 3 index in front of me
//i-1,j+1,    i,j+1,     i+1,j+1     this will be for n-1,0 ball
//now for 0,n-1 ball
//it will be 
//i+1,j-1,    i+1,j      i+1,j+1    
//now my target is to reach n-1,n-2 box for n-1,0 ball 
//for 0,n-1 ball my target is to reach n-2,n-1 box
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        if (n == 0) return 0;
        if (n == 1) return fruits[0][0];

        // 1) Child from (0,0) → (n-1,n-1) along the main diagonal
        long long ans = 0;
        for (int i = 0; i < n; i++) 
            ans += fruits[i][i];

        // 2) Child from (n-1,0) staying below the diagonal, ending at (n-1,n-2)
        //    dpLL[i][j] = max fruits reaching (i,j)
        vector<vector<long long>> dpLL(n, vector<long long>(n, LLONG_MIN));
        dpLL[n-1][0] = fruits[n-1][0];
        // move column by column
        for (int j = 1; j <= n-2; j++) {
            // valid rows: i>j to stay below the diagonal
            for (int i = j+1; i < n; i++) {
                long long best = LLONG_MIN;
                // can come from (i-1,j-1), (i,j-1), (i+1,j-1)
                if (i-1 >= 0)      best = max(best, dpLL[i-1][j-1]);
                best = max(best, dpLL[i][j-1]);
                if (i+1 < n)       best = max(best, dpLL[i+1][j-1]);
                dpLL[i][j] = best + fruits[i][j];
            }
        }
        ans += dpLL[n-1][n-2];

        // 3) Child from (0,n-1) staying above the diagonal, ending at (n-2,n-1)
        //    dpUR[i][j] = max fruits reaching (i,j)
        vector<vector<long long>> dpUR(n, vector<long long>(n, LLONG_MIN));
        dpUR[0][n-1] = fruits[0][n-1];
        // move row by row
        for (int i = 1; i <= n-2; i++) {
            // valid cols: j>i to stay above the diagonal
            // also cannot start too far left, so j ≥ n-1−i
            int startJ = max(i+1, n-1 - i);
            for (int j = startJ; j < n; j++) {
                long long best = LLONG_MIN;
                // can come from (i-1,j-1), (i-1,j), (i-1,j+1)
                if (j-1 >= 0)      best = max(best, dpUR[i-1][j-1]);
                best = max(best, dpUR[i-1][j]);
                if (j+1 < n)       best = max(best, dpUR[i-1][j+1]);
                dpUR[i][j] = best + fruits[i][j];
            }
        }
        ans += dpUR[n-2][n-1];

        return int(ans);

    }
};