class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>same;
        for(int i=0;i<nums.size()-1;i++)
        {
            if((nums[i]%2)==(nums[i+1]%2))
            {
                same.push_back(i);
            }
        }
        vector<bool>ans;
        for(int i=0;i<queries.size();i++)
        {
            int s=queries[i][0];
            int e=queries[i][1];
            if(s==e)
            {
                ans.push_back(true);
                continue;
            }
            auto it = lower_bound(same.begin(), same.end(), s);
            if (it != same.end() && *it < e)
            {
                ans.push_back(false);
            }
            else
            {
                ans.push_back(true);
            }

        }

        return ans;

    }
};