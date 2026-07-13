class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        deque<int>dq;
        vector<int>ans(nums.size());
        for(int i=2*nums.size();i>=0;i--)
        {
            int c=i%(nums.size());
            while((!dq.empty()) && (dq.back()<=nums[c]))
            {
                dq.pop_back();
            }
            if(!dq.empty() && dq.back()>nums[c])
            {
                ans[i%(nums.size())]=dq.back();
            }
            else
            {
                ans[i%(nums.size())]=-1;
            }
            dq.push_back(nums[c]);
        }

        return ans;
    }
};