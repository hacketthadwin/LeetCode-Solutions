class Solution {
public:
bool g(long long m,vector<int>& candies, long long k)
{
    long long total_alloted=0;
    for(int i=0;i<candies.size();i++)
    {
        total_alloted +=(candies[i]/m);
    }

    if(total_alloted>=k)return true;
    return false;
}
    int maximumCandies(vector<int>& candies, long long k) {
        long long total_candies= accumulate(candies.begin(),candies.end(),0LL);
        if(total_candies<k)
        {
            return 0;
        }
        long long l=0,r=LLONG_MAX;
        while(r-l>1)
        {
            long long m=(l+((r-l)/2));
            if(g(m,candies,k))
            {
                l=m;
            }
            else
            {
                r=m;
            }
        }
        return l;
    }
};