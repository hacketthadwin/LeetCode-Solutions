class Solution {
public:
    unordered_map<int,vector<int>>mp;
    unordered_map<int,int>curr_indx;
    Solution(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]].push_back(i);
            curr_indx[nums[i]]=0;
        }
    }
    
    int pick(int target) {
        int ans= mp[target][curr_indx[target]];
        curr_indx[target]++;
        curr_indx[target]=curr_indx[target]%mp[target].size();
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */