class Solution {
public:
    string frequencySort(string s) {
       map<char,int>mp;
       for(int i=0;i<s.size();i++)
       {
            mp[s[i]]++;
       }

       vector<pair<int,char>>v;
       for(auto m:mp)
       {
            v.push_back({m.second,m.first});
       }

       sort(v.rbegin(),v.rend());
       string ans="";
       for(int i=0;i<v.size();i++)
       {
            for(int j=0;j<v[i].first;j++)
            {
                ans+=v[i].second;
            }
       }

       return ans;
    }
};