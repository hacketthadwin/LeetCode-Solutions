class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int i=0;
        int n=costs.size();
        int ans=0;
        while(i<n && coins>0)
        {
            if((coins-costs[i])<0)
            {
                break;
            }
            coins=coins-costs[i];
            i++;
            ans++;


        }

        return ans;
    }
};