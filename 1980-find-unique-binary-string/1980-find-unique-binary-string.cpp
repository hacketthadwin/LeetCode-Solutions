class Solution {
public:
string ans;
    void rec(int idx, string curr, vector<string>& nums)
    {
        if(idx>=curr.size())
        {
            return;
        }
        string t = curr;
        t[idx]='1';
        string s = curr;
        s[idx]='0';
        bool found1=false,found2=false;
        for(int i=0;i<nums.size();i++)
        {
            if(t==nums[i])
            {
                found1=true;
            }
            if(s==nums[i])
            {
                found2=true;
            }
        }
        if((found1 && found2) == false)
        {
            if(found1==false)
            {
                ans=t;
            }
            if(found2==false)
            {
                ans=s;
            }
            return;
        }
        rec(idx+1,t,nums);
        rec(idx+1,s,nums);
    }
    string findDifferentBinaryString(vector<string>& nums) {
        // rec(0,nums[0],nums);
        // return ans;

        //now there is one alternate mathematical approach too which is based on i guess probability, never knew before, got to know through discussions, the approach is cantor's diagonal argument, the proof of this argument can be seen on YT.
        // it just states that we can get unique answer by diagonal elements in a n*n matrix
        int n=nums.size(), len=nums[0].size();
        string ans=string(len,'1');
        for(int i=0; i<n; i++)
        {
            ans[i]=('1'-nums[i][i])+'0';
        }
        return ans;


    }
};