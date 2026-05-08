class Solution {
public:
    int dp[101][10001];
    int rec(int n,int c,int i)
    {
        //base case
        if(n == 1) return c - i;  //if only one egg is remaining then no need to check, //just go to final stage and from there start coming down and check where egg breaks
        if(c - i == 0) return 0;//this is same as if (i==c) then i reached at top floor, from there no moves remaining
        //cache check
        if(dp[n][c-i]!=-1)return dp[n][c-i]; //i have replaced dp[n][i] to dp[n][c-i] because both c and i are changing, if i get the difference between top floor and current floor then also i can cache the answer
        //compute and transition
        int ans=1e9;
        for(int k=i;k<c;k++)
        {
            int tempans1,tempans2;
            //if egg is broken (then max limit will be k only and not c)
            if(dp[n-1][k-i]!=-1)
            {
                tempans1=dp[n-1][k-i];
            }
            else
            {
                tempans1= rec(n-1,k,i);
                dp[n-1][k-i]=tempans1;
            }
            //if egg is not broken(i am still left with all eggs but the limit can be greater)
            if(dp[n][c-(k+1)]!=-1)
            {
                tempans2=dp[n][c-(k+1)];
            }
            else
            {
                tempans2= rec(n,c,k+1);
                dp[n][c-(k+1)]=tempans2;
            }
            //now as i used one turn, so i need to add 1 to the answer and i will take max of above for worst case possible
            int tempans3= 1 + max(tempans1,tempans2);
            //now i will simply find minimum of all answer as answer
            ans=min(ans,tempans3);
            
        }
        return dp[n][c-i]=ans;
    }
    int rec2(int n,int c,int i)
    {
        //base case
        if(n == 1) return c - i;  //if only one egg is remaining then no need to check, //just go to final stage and from there start coming down and check where egg breaks
        if(c - i == 0) return 0;//this is same as if (i==c) then i reached at top floor, from there no moves remaining
        //cache check
        if(dp[n][c-i]!=-1)return dp[n][c-i]; //i have replaced dp[n][i] to dp[n][c-i] because both c and i are changing, if i get the difference between top floor and current floor then also i can cache the answer
        //compute and transition
        int ans=1e9;
        int l=i,r=c-1,m;
        while(l<=r)
        {
            m=(l+((r-l)/2));
            int tempans1,tempans2;
            //if egg is broken (then max limit will be k only and not c)
            if(dp[n-1][m-i]!=-1)
            {
                tempans1=dp[n-1][m-i];
            }
            else
            {
                tempans1= rec2(n-1,m,i);
                dp[n-1][m-i]=tempans1;
            }
            //if egg is not broken(i am still left with all eggs but the limit can be greater)
            if(dp[n][c-(m+1)]!=-1)
            {
                tempans2=dp[n][c-(m+1)];
            }
            else
            {
                tempans2= rec2(n,c,m+1);
                dp[n][c-(m+1)]=tempans2;
            }
            //now as i used one turn, so i need to add 1 to the answer and i will take max of above for worst case possible
            int tempans3= 1 + max(tempans1,tempans2);
            //now i will simply find minimum of all answer as answer
            ans=min(ans,tempans3);
            if(tempans1<tempans2)
            {
                l=m+1;
            }
            else
            {
                r=m-1;
            }
        }
        return dp[n][c-i]=ans;
    }
 int ultarec(int n, int c)
{
    int ultadp[n+1][c+1]; //first one is n

    for(int i = 0; i <= c; i++)
    {
        ultadp[1][i] = i;  //if only one egg is remaining then no need to check, //just go to final stage and from there start coming down and check where egg breaks
    }

    for(int i = 0; i <=n; i++)
    {
        ultadp[i][0] = 0; //this is same as if (i==c) then i reached at top floor, from there no moves remaining
    }

    for(int i = 2; i <= n; i++)
    {
        for(int j = 1; j <= c; j++)
        {
            int ans = 1e9;
            for(int k = 1; k <= j; k++) // drop from 1 to j    and it is for everytime, we are finding minimum after going inside this but it all starts from 1 only
            {
                //if egg is broken (then max limit will be k only and not c)
                // int tempans1= rec(n-1,k,i);
                int tempans1 = ultadp[i - 1][k - 1];    //as i said that 'i' starts from 1, so here also it will start from 1 so i=1;
                //if egg is not broken(i am still left with all eggs but the limit can be greater)
                // int tempans2= rec(n,c,k+1);
                //j-(k+1)+1 because j can be equal to k and if that happens then j-(k+1) can become -1, so to clear the offset, added extra 1
                int tempans2 = ultadp[i][j - k];
                //now as i used one turn, so i need to add 1 to the answer and i will take max of above for worst case possible
                int tempans3 = 1 + max(tempans1, tempans2);
                //now i will simply find minimum of all answer as answer
                ans = min(ans, tempans3);
            }
            ultadp[i][j] = ans;
        }
    }

    return ultadp[n][c];
}

//after this, it will require binary search to solve and submit, because i am finding minimum of maximum, so a predicate function can be formed and then it can be solved
//instead of looping "k" through all the numbers from i to n-1, we can use binary search and jump instead of looping from k=1 to n-1

    int superEggDrop(int n, int k)
    {
        memset(dp,-1,sizeof(dp));
        // return ultarec(n,k);
        return rec2(n,k,0);
    }
};