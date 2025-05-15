class Solution {
public:
int dp[201][201];
    int rec(int n, int k, vector<vector<int>>& stayscore, vector<vector<int>>& travelscore,int currn,int currday)
    {
        //basecase
        if (currday == k) {
            return 0;
        }
        
        //cache check
        if(dp[currn][currday]!=-1)return dp[currn][currday];

        //compute and transition
        // Stay in the current city
        int stay = stayscore[currday][currn] + rec(n, k, stayscore, travelscore, currn, currday + 1);
        int ans = stay;
        
        // Try traveling to each other city
        for (int i = 0; i < n; i++) {
            if (i == currn) continue;
            int travel = travelscore[currn][i] + rec(n, k, stayscore, travelscore, i, currday + 1);
            ans = max(ans, travel);
        }
        
        return dp[currn][currday]=ans;
    }
    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        int ans=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            ans=max(ans,rec(n,k,stayScore,travelScore,i,0));
        }
        return ans;
    }
};