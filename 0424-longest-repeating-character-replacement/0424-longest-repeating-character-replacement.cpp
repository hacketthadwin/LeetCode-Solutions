class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0,ans=1;
        map<char,int>mp;
        int max_freq=0;
        while(r<s.size())
        {
            mp[s[r]]++;
            max_freq=max(max_freq,mp[s[r]]);
            while(((r-l+1)-max_freq)>k)
            {
                mp[s[l]]--;
                l++;
                max_freq=max(max_freq,mp[s[l]]);
            }
            ans=max(ans,r-l+1);
            r++;
        }

        return ans;
    }
};