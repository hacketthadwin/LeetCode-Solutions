class Solution {
public:
    string clearDigits(string s) {
       string ans="";
       for(int i=0;i<s.size();i++)
       {
            if(s[i]>='0' && s[i]<='9')
            {
                if(ans.size()>0)
                {
                    ans.erase(ans.end()-1);
                }
            }
            else
            {
                ans+=s[i];
            }
       }
       return ans;
    }
};