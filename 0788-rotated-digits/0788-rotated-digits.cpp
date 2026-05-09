class Solution {
public:
vector<char>limit;
int dp[1000000][2][2];
    int rec(int indx, int tight,int changed, string num)
    {
        if(indx==num.size())
        {
            if(changed==1)return 1;
            return 0;
        }
        if(dp[indx][tight][changed]!=-1)return dp[indx][tight][changed];
        int ans=0;

        //added this max_limit variable for proper tight handling
        int max_limit=9;

        //if tight is 1 then only current digit is restricted
        if(tight==1)
        {
            max_limit=(limit[indx]-'0');
        }

        for(int i=0;i<=max_limit;i++)
        {
            //invalid digits after rotation
            if(i==3 || i==4 || i==7) continue;

            int next_tight=0;

            if(tight==1 && i==(limit[indx]-'0'))
            {
                next_tight=1;
            }

            //removed this condition because max_limit already handles it
            // if(tight==1 && i>(limit[indx]-'0'))
            // {
            //     break;
            // }

            //removed unnecessary i<=limit[indx]-'0' check
            //because tight handling already done above

            if(i==2 || i==5 || i==6 || i==9)
            {
                //changed propagation
                //once changed becomes 1, it should stay 1
                ans+=rec(indx+1,next_tight,1,num);
            }
            else
            {
                ans+=rec(indx+1,next_tight,changed,num);
            }
        }
        return dp[indx][tight][changed]=ans;
    }

    int rotatedDigits(int n) {
        string num = to_string(n);
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<num.size();i++)
        {
            limit.push_back(num[i]);
        }
        return rec(0,1,0,num);
    }
};