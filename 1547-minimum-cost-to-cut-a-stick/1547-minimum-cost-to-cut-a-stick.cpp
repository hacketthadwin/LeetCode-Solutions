class Solution {
public:

//ok so this was my code and this is wrong because my logic was wrong, my logic is itself flawed, i thought that if i cut at the centre of current rod, then i will get the minimum cost, but what if the next cut will only have options near the end, then my total cost may increase, that's why take every cuts array element and check if this is minimum or not in each recursive calls
//everything else is same as my logic
// int rec(vector<int>& cuts,int l1,int r1)
// {
//     //base case
//     if(r1-l1==0)
//     {
//         return 0;
//     }
//     //compute and transition

//     int ans=0;


//     int cost=r1-l1;
//     int cand1=lower_bound(cuts.begin(),cuts.end(),((r1+l1)/2))-cuts.begin();
//     int cand12=0;
//     if(cand1>0)cand12=cand1-1;
//     int fincand1=-1;
//     if(abs(cand1-((r1+l1)/2))>abs(cand12-((r1+l1)/2)))
//     {
//         fincand1=cand12;
//     }
//     else
//     {
//         fincand1=cand1;
//     }

//     cost+=rec(cuts,l1,fincand1);
//     cost+=rec(cuts,fincand1,r1);

//     return cost;

// }
int dp[110][110];
int rec(vector<int>& cuts,int i,int j)
{
        if (i + 1 >= j) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int ans = INT_MAX;

        for (int k = i + 1; k < j; ++k) {
            int cost = (cuts[j] - cuts[i]) + rec(cuts, i, k) + rec(cuts, k, j);
            ans = min(ans, cost);
        }

        return dp[i][j] = ans;

}
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        memset(dp, -1, sizeof(dp));

        return rec(cuts, 0, cuts.size() - 1);
    }
};