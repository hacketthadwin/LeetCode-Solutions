class Solution {
public:

    int maxProfit(vector<int>& prices) {

        int min_till_now=INT_MAX;
        int ans=0;
        for(int i=0;i<prices.size();i++)
        {
            min_till_now=min(min_till_now,prices[i]);
            ans=max(ans,prices[i]-min_till_now);
        }
        return ans;

    }
};