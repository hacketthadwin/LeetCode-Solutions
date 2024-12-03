class Solution {
public:
    vector<int>arr;
    int dp[1000][1000];
    int solve(int idx,int d)
    {
        //basecase
        if(d==0)
        {
            return idx == arr.size() ? 0 : INT_MAX; 
        }
        //cache check
        if(dp[idx][d]!=-1)return dp[idx][d];
        //compute and transition
        int maxdifficulty=INT_MIN;
        int result;
        int finalresult=INT_MAX;
        for(int i=idx;i<=arr.size()-d;i++)   //here we will have <= and not only < because d=0 case will never come here
        {
            maxdifficulty=max(maxdifficulty,arr[i]);
            result=solve(i+1,d-1);
            if (result != INT_MAX) { 
                finalresult = min(finalresult, maxdifficulty + result);
            }

        }
        return dp[idx][d]=finalresult;

    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        arr=jobDifficulty;
        memset(dp,-1,sizeof(dp));
         if (d > jobDifficulty.size()) return -1; 
        return solve(0, d);
        
    }
};