class Solution {
public:
    bool isAnagram(string s, string t) {
        //i will simply count the number of each alphabet, every number of s should be equal to t
        vector<int>s_count(26,0),t_count(26,0);
        if(s.size()!=t.size())return false;
        for(int i=0;i<s.size();i++)
        {
            s_count[s[i]-'a']++;
            t_count[t[i]-'a']++;
        }

        for(int i=0;i<s_count.size();i++)
        {
            if(s_count[i]!=t_count[i])
            {
                return false;
            }
        }
        return true;
    }
};