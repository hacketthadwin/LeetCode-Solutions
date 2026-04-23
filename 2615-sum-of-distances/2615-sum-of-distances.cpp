class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<long long,vector<long long>>mp;
        for(long long i=0;i<nums.size();i++)
        {
            mp[nums[i]].push_back(i);
        }
        vector<long long>ans(nums.size());
        for(auto m:mp)
        {
            if (m.second.size()==1)
            {
                ans[m.second[0]]=0;
                continue;
            }
            vector<long long>prefix(m.second.size(),0);
            prefix[0]=m.second[0];
            for(long long i=1;i<m.second.size();i++)
            {
                prefix[i]= prefix[i-1] + m.second[i];
            }
            for(long long i=0;i<m.second.size();i++)
            {
                //for each m.second[i], we will save it there only

                ans[m.second[i]] = ((prefix[m.second.size()-1]-prefix[i])-((long long)((m.second.size()-i-1)*m.second[i]))) + (((long long)((i+1)*m.second[i]))-(prefix[i])); 
            }
        }

        return ans;
    }
};


// 1,2,5,7,8,10 = 33 
// 6 numbers
// 1+4+6+7+9 = 27 = 33 - 6
// 1+3+5+6+8 = 23 = 33 - 10
// 4+3+2+3+5 = 17 = 33 - 16
// 6+5+2+1+3 = 17 = 33 - 16
// 7+6+3+1+2 = 19 = 33 - 14
// 9+8+5+3+2 = 27 = 33 - 6