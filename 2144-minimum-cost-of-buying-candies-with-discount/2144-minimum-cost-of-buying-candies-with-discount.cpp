class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int ans=0;
        sort(cost.rbegin(),cost.rend());
        for(int i=1;i<=cost.size();i++)
        {
            if(i%3==0)continue;
            ans+=cost[i-1];
        }
        return ans;
    }
};