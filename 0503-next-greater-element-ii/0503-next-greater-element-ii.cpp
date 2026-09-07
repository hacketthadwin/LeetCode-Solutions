class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st;
        vector<int>ans(nums.size(),-1);
        for(int i=2*nums.size()-1;i>=0;i--)
        {
            int k=i%(nums.size());
            while(!st.empty() && nums[st.top()]<=nums[k])
            {
                st.pop();
            }

            if(!st.empty()) {
                ans[k] = nums[st.top()];
            }


            st.push(k);
        }
        return ans;
    }
};