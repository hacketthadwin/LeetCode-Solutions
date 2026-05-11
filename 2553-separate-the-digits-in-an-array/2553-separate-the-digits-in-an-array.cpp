class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<string>v;
        for(int i=0;i<nums.size();i++)
        {
            v.push_back(to_string(nums[i]));
        }
        vector<int>ans;
        for(int i=0;i<v.size();i++)
        {
            for(int j=0;j<v[i].size();j++)
            {
                ans.push_back((v[i][j]-'0'));
            }
        }
        return ans;
    }
};