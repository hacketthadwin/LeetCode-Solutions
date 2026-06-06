class Solution {
public:
int dp[2005][2005];
    bool rec(int idx,int jdx,string&s, string&p )
    {
        //base case
        if(jdx==p.size())
        {
            if(idx==s.size())return true;
            return false;
        }
        if(idx==s.size())
        {
            bool not_star=true;
            for(int j=jdx;j<p.size();j++)
            {
                if(p[j]!='*')
                {
                    not_star=false;
                    break;
                }
            }
            return not_star;

        }
        //cache check
        if(dp[idx][jdx]!=-1)return dp[idx][jdx];
        
        //compute and transition
        bool ans=false;
        if((p[jdx]!='?' && p[jdx]!='*') && p[jdx]!=s[idx])return false;
            if((idx<s.size()) && ((p[jdx]=='?') || (p[jdx]==s[idx])))
            {
                ans|=rec(idx+1,jdx+1,s,p);
            }
            if(p[jdx]=='*')
            {
                ans|=rec(idx,jdx+1,s,p);  
                ans|=rec(idx+1,jdx,s,p); 
 
            }
        return dp[idx][jdx]=ans;
    }
    bool isMatch(string s, string p) {
        if(p.size()==0 && s.size()!=0)return false;
        memset(dp,-1,sizeof(dp));


        return rec(0,0,s,p);
    }
};