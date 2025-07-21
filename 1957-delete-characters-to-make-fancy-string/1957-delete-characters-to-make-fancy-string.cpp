class Solution {
public:
    string makeFancyString(string s) {
        int curr_char=s[0];
        int cnt=0;
        vector<int>is_taken(s.size(),1);
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==curr_char)
            {
                cnt++;
            }
            else
            {
                curr_char=s[i];
                cnt=1;
            }
            if(cnt>=3)
            {
                is_taken[i]=0;
            }
        }

        string ans="";
        for(int i=0;i<s.size();i++)
        {
            if(is_taken[i]==1)ans+=s[i];
        }
        return ans;
    }
};