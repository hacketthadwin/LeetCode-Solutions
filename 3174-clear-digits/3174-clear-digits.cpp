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
       //what i learnt from this
        //whenever you get bug of \u0000 or any null char which you are not expecting, it is difficult to remove them too, but the bug is that you are probably iterating to the end of string like i<=s.size(), this was my bug here
    }
};