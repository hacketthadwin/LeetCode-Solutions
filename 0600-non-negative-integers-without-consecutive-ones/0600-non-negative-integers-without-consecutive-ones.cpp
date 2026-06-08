class Solution {
public:
int dp[100][2][2];
int rec(int idx,bool tight, string&s, int prev)
{
    if(idx==s.size())return 1;
    
    //so i will be either choosing 1 or 0..there is not much option like 0 to 9
    
    //ok ok a bit of thinking required...if we are running in tight condition...then it means i can take 0 and 1 both only if s[idx] is 1...else i can only take 0, if we are not in tight condition..then there is freedom to take whatever we want
    if(dp[idx][tight][prev]!=-1)return dp[idx][tight][prev];
    int ans=0;
    if(tight)
    {
        if(s[idx]=='1')
        {
            //i can take both 0 and 1..if i give it 0 here..then it means..i can will pass tight as false..else i will pass it as true
            ans+=rec(idx+1,false,s,0);
            if(prev!=1)ans+=rec(idx+1,true,s,1);
        }
        else
        {
            ans+=rec(idx+1,true,s,0);
        }
    }
    else
    {
        ans+=rec(idx+1,tight,s,0);
        if(prev!=1)ans+=rec(idx+1,tight,s,1);
    }
    return dp[idx][tight][prev]=ans;
}
    int findIntegers(int n) {
        string r="";
        for(int i=0;i<=31;i++)   //1 bug i made was always start this from 0..not 1...otherwise you will miss the last bit
        {
            r+= ((n>>i) & 1) ? '1' : '0' ;
        }
        reverse(r.begin(),r.end());
        memset(dp,-1,sizeof(dp));
        // int temp=stoi(r);
        // return temp;
        //now its just simple digit dp problem
        return rec(0,true,r,0);
    }
};
