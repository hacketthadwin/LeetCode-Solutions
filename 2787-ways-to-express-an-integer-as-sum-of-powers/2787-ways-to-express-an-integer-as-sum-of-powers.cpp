class Solution {
public:
    int numberOfWays(int n, int x) {
        //see first of all let's solve this using obvious way(storing powers)
        const int mod=1000000007;
        vector<int>powers;
        for(int i=1;i<=n;i++)
        {
            int temp=1;
            for(int j=0;j<x;j++)
            {
                
                temp*=i;
                if(temp>n)break;
            }
            if(temp>n)break;
            powers.push_back(temp);
        }
        vector<int>dp(n+5,0);
        dp[0]=1;
        for(int j=0;j<powers.size();j++)
        {
            for(int i=n;i>=1;i--)
            {
                if((i-powers[j])>=0){dp[i]=(dp[i]+dp[i-powers[j]])%mod;}
            }
        }

        return dp[n];


        //see you don't always need to calculate the powers initally, you can also calculate it on point but that is waste of time
    }
};