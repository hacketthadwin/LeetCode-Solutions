class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        unordered_map<int,int>mp;
        vector<int>ans;
        int n=changed.size();
        sort(changed.begin(),changed.end());
        for(int i=0;i<n;i++)
        {
            mp[changed[i]]++;
        }
        for(int i=0;i<n;i++)
        {
            //i am currently at changed[i], if 2*changed[i] is present, if it is present, then good, i will mark that i have visited both the current element and the 2* element, and i will push the current element into the answer vector
            //if the changed[i] is already 0, it will mean that i have visited it already
            //if the changed[i] is 0, then i will check if it is present even times or not, if not then i will return {}
            if(mp[changed[i]]==0)continue;
            if(mp[2*changed[i]]==0)return {}; //if changed[i] is present and 2*changed[i] is not present then also return {} because that is not allowed
            if(changed[i]==0 && mp[changed[i]]%2!=0)return {};
            ans.push_back(changed[i]);
            mp[changed[i]]--;
            mp[2*changed[i]]--;
        }
        return ans;
    }
};