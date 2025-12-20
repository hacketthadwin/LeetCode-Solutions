class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans=0;
        int curr_cnt=1;
        for(int i=0;i<prices.size()-1;i++)
        {
            if(prices[i]-prices[i+1]==1)
            {
                curr_cnt++;
            }
            else
            {
                ans+=((long long)curr_cnt*(curr_cnt+1))/2;
                curr_cnt=1;
            }
        }
        ans+=((long long)curr_cnt*(curr_cnt+1))/2;
        return ans;
    }
};