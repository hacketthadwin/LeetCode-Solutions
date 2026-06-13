class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        unordered_map<int,char>mp;
        for(int i=0;i<26;i++)
        {
            mp[i]=('z'- i);
        }   
        string ans="";
        for(int i=0;i<words.size();i++)
        {
            int sum=0;
            for(auto c:words[i])
            {
                sum+=weights[c-'a'];
            }
            sum%=26;
            ans+=mp[sum];
        }
        return ans;
    }
};