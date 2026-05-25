class Solution {
public:
// bool is_possible=false;
// int dp[100005];
// bool rec(int idx,string&s, int minJump, int maxJump)
// {
//     //base case
//     if(idx==s.size()-1)
//     {
//         return true;
//     }
//     //cache check
//     if(dp[idx]!=-1)return dp[idx];
//     //compute and transition
//     bool is_possible=false;
//     for(int i=idx+minJump;i<=min(idx+maxJump,(int)s.size()-1);i++)
//     {
//         if(s[i]=='0')
//         {
//             is_possible|=rec(i,s,minJump,maxJump);
//         }
//     }

//     return dp[idx]=is_possible;
// }
    bool canReach(string s, int minJump, int maxJump) {
        // return rec(0,s,minJump,maxJump);

        //ok so if this is giving mle even after memoisation, then it means it expects some other moves, so i will have to check from i+maxJump-minJump to i+maxJump, then i guess it can give correct answer
        //i was missing the reachable idea, it was a good learning question, that sometimes...choosing the iterative dp may work in miracles
        int dp[s.size()+1];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        int reachable=0;
        for(int i=1;i<s.size();i++)
        {
            //the below is checking from minJump
            if(i-minJump>=0 && dp[i-minJump])
            {
                reachable++;
            }
            //the below is leaving the reachability from the out of range previous index
            if(i-maxJump-1>=0 && dp[i-maxJump-1])
            {
                reachable--;
            }

            if(s[i]=='0' && reachable>0)
            {
                dp[i]=1;
            }
        }

        return dp[s.size()-1];
    }
};