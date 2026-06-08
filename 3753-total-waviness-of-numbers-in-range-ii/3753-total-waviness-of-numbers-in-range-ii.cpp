// class Solution {
// public:
// //so i have forgotten the basic structure of digit dp...let's try to recall...we create a function...then we do that func(r+1) - func(l) to get for all values in the range...also we traverse digit by digit...we have 3 parameters...first is index...second is tight..and third is the value till now...we need to pass it because it gets transferred downwards

//     long long dp(int indx, bool tight, bool leading_zeroes, int prev_digit,bool more_than_prev string&num, int n)
//     {
//         if(indx==n-1)return 0;
//         long long ans=0;
//         long long lb=0;
//         if(more_than_prev)lb=prev_digit;
//         long long ub = tight ? (num[indx]-'0') : 9;
//         long long tight_val= tight ? (num[indx]-'0') : 9
//         if(!more_than_prev)ub=min(ub,prev_digit);
//         for(int i=lb;i<=ub;i++)
//         {
//             int some_value=0;
//             // if(i>prev_digit)
//             // {
//             //     some_value= (tight && i==ub)? min(num[indx+1]-'0'-1,i-1) : i-1;
//             //     if(some_value<0)some_value=0;
//             //     //i need to make sure that next digit should be less than i...
//             //     ans= ans + (some_value)  + dp(indx+1,(tight && i==ub),(leading_zeroes && i==0),i,num,n);
//             // }   
//             // if(i<prev_digit)
//             // {
//             //     some_value= (tight && i==ub)? max(num[indx+1]-'0' - i - 1,0) :9-i-1;
//             //     if(some_value<0)some_value=0;
//             //     ans= ans + (some_value)  + dp(indx+1,(tight && i==ub),(leading_zeroes && i==0),i,num,n);
//             // }
//             ans+=dp(indx+1,(tight && i==tight_val),(leading_zeroes && i==0),i,true,num,n);
//             ans+=dp(indx+1,(tight && i==tight_val),(leading_zeroes && i==0),i,false,num,n);
//         }
//         return ans;
//     }
//     long long totalWaviness(long long num1, long long num2) {
//         //yeah now it is digit dp...nice
//         string snum1=to_string(num1-1);
//         string snum2=to_string(num2);
//         // int preceding_zeroes=snum2.size()-snum1.size();
//         // string fin_snum1="";
//         // for(int i=0;i<preceding_zeroes;i++)
//         // {
//         //     fin_snum1+='0';
//         // }
//         // fin_snum1+=snum1;
//         //yeah..we dont need to add preceding zeroes on our own...it can be handled

//         long long cnt_of_snum1=dp(1,true,true,snum1[0]-'0',snum1,snum1.size());
//         long long cnt_of_snum2=dp(1,true,true,snum2[0]-'0',snum2,snum2.size());
//         return cnt_of_snum2 - cnt_of_snum1;
//     }
// };
class Solution {
public:
//my idea was totally off..because i knew we will need 3 digits for this...but i never knew..we will need to store 2 of previous digit
pair<long long, long long> dp[32][2][15][15][2];  //first one denotes sum..second one denotes count
    pair<long long,long long> rec(int indx, bool tight, int prev_prev,int prev, bool leading_zeroes, string&num, int n)
    {
        if(indx==n)return {0,1};
        if(dp[indx][tight][prev_prev][prev][leading_zeroes].first!=-1)return dp[indx][tight][prev_prev][prev][leading_zeroes];
        int lb=0;
        int ub = tight?(num[indx]-'0'):9;
        long long ans=0;
        long long cnt=0;
        for(int i=lb;i<=ub;i++)
        {            
            if(prev_prev==11 && prev==11)
            {
                if(leading_zeroes && i==0)
                {
                    pair<long long, long long>p=rec(indx+1,(tight && i==ub),11,11,(leading_zeroes && i==0),num,n);
                    ans+=p.first;
                    cnt+=p.second;
                }
                else
                {
                    pair<long long,long long>p=rec(indx+1,(tight && i==ub),11,i,(leading_zeroes && i==0),num,n);
                    ans+=p.first;
                     cnt+=p.second;
                }
                continue;
            }
            else if(prev_prev==11 && prev!=11)
            {
                pair<long long,long long>p=rec(indx+1,(tight && i==ub),prev,i,(leading_zeroes && i==0),num,n);
                ans+=p.first;
                 cnt+=p.second;
                continue;
            }
           else if(prev>prev_prev && prev>i)
            {
                pair<long long,long long>p=rec(indx+1,(tight && i==ub),prev,i,(leading_zeroes && i==0),num,n);

                ans=ans+p.first+p.second;
                cnt+=p.second;
                continue;
            }
           else if(prev<prev_prev && prev<i)
            {
                pair<long long,long long>p=rec(indx+1,(tight && i==ub),prev,i,(leading_zeroes && i==0),num,n);
                ans=ans+p.first+p.second;
                cnt+=p.second;
                continue;
            }
            pair<long long,long long>k=rec(indx+1,(tight && i==ub),prev,i,(leading_zeroes && i==0),num,n);
            ans= ans+k.first;
            cnt+=k.second;
        }
        return dp[indx][tight][prev_prev][prev][leading_zeroes]={ans,cnt};
    }
    long long totalWaviness(long long num1, long long num2) {
        //all you need is a damn break....go touch some grass
        string snum1=to_string(num1-1);
        string snum2=to_string(num2);
        memset(dp,-1LL,sizeof(dp));
        long long a= rec(0,true,11,11,true,snum2,snum2.size()).first ;
        memset(dp,-1,sizeof(dp));   //here is a twist that we need to do memset twice..remember this thing in digit dp problem
        long long b= rec(0,true,11,11,true,snum1,snum1.size()).first;
        return a-b;
    }
};