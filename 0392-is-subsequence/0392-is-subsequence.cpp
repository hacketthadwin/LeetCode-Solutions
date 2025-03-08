class Solution {
public:
    bool isSubsequence(string s, string t) {
        int cnt=0;
        for(int i=0,j=0;i<s.size() && j<t.size();j++)
        {
            if(s[i]==t[j])
            {
                i++;
                cnt++;
            }
        }
        if(cnt==s.size())return true;
        return false;
        
    }
};