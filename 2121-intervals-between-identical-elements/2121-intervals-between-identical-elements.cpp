class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        unordered_map<long long,vector<long long>>mp;
        for(long long i=0;i<arr.size();i++)
        {
            mp[arr[i]].push_back(i);
        }
        vector<long long>ans(arr.size());
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
                ans[m.second[i]] = ((prefix[m.second.size()-1]-prefix[i])-((long long)((m.second.size()-i-1)*m.second[i]))) + (((long long)((i+1)*m.second[i]))-(prefix[i])); 
            }
        }

        return ans;
    }
};