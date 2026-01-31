class Solution {
public:
    int numberOfSubstrings(string s) {
        //this can get solved using map
        map<char,int>mp;
        int l=0,r=0,ans=0;
        while(r<s.size())
        {
            mp[s[r]]++;
            while((l<=r) && mp['a']>=1 && mp['b']>=1 && mp['c']>=1)
            {
                ans+=(s.size()-r);
                mp[s[l]]--;
                l++;
            }
            
            r++;
        }
        return ans;
    }
};