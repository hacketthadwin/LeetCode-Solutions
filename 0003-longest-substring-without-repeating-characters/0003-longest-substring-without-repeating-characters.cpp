class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0;
        map<char,int>mp;
        if(s.size()==0)return 0;
        int maxi=1;
        while(r<s.size())
        {
            if(mp.count(s[r]))
            {
                l=max(l,mp[s[r]]+1);
            }
            mp[s[r]]=r;
            maxi=max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};