class Solution {
public:
const int MOD = 1e9 + 7;

long long rec(long long x,long long n)
{
    if(n==0)return 1;

    long long rec_soln=rec(x,n/2);
    long long ans=1;

    if(n%2==0)
    {
        ans=((rec_soln%MOD)*(rec_soln%MOD))%MOD;
    }
    else
    {
        ans=(((rec_soln%MOD)*(rec_soln%MOD))%MOD*x)%MOD;
    }

    return ans;
}

long long myPow(long long x,long long n) {
    if(x==0)return 0;
    if(x==1)return 1;
    if(n==1)return x;
    if(n==0)return 1;

    long long ans=1;
    long long rec_soln=rec(x,n/2);

    if(n%2==0)
    {
        ans=((rec_soln%MOD)*(rec_soln%MOD))%MOD;
    }
    else
    {
        ans=(((rec_soln%MOD)*(rec_soln%MOD))%MOD*x)%MOD;
    }

    return ans;
}

    int countGoodNumbers(long long n) {
        return (int)((myPow(5,(n+1)/2)*myPow(4,n/2))%MOD);
    }
};