class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        //now my task will be to first find all the contigous range of 1 surrounded by 0
        //then after i can do is convert them to 0 and then convert them to 1
        vector<pair<int,pair<int,int>>>v;
        int last_zero=INT_MAX;
        for(int i=0;i<s.size();)
        {
            if(s[i]=='0')last_zero=min(last_zero,i);
            if(i!=0 && s[i-1]=='0' && s[i]=='1')
            {
                int a=i;
                while(i<s.size() && s[i]=='1')i++;
                if(i<s.size())
                {
                    int total_len=(a-last_zero);  //i initially did both counting of current block of 1 and left block..now only left block
                    int last_one=i-1;
                    last_zero=i;
                    int cnt_zero=0;
                    while(i<s.size() && s[i]=='0')
                    {
                        cnt_zero++;
                        i++;
                    }
                    total_len+=cnt_zero;
                    v.push_back({total_len,{a,last_one}});
                }
            }
            else
            {
                i++;
            }
        }
        //this v will contain all the contigous 1 surrounded by 0 with their length...
        
        // if(v.size()>0)return v[0].first;
        // return -1;

        vector<int>prefix_sum(s.size(),0);
        if(s[0]=='1')prefix_sum[0]++;
        for(int i=1;i<s.size();i++)
        {
            prefix_sum[i]=prefix_sum[i-1];
            if(s[i]=='1')prefix_sum[i]++;
        }
       

        //so i will pick the v[0]th element..and then will pick all the zeroes before it..and after it
if(v.size()>0){         sort(v.rbegin(),v.rend());
        // int extra_ones= prefix_sum[v[0].second.first-1] + (prefix_sum.back()-prefix_sum[v[0].second.second]) ;
        int extra_ones=prefix_sum.back(); //all ones since i am not counting the ones in the total_len thing

        return v[0].first+extra_ones;}
        else
        {
            return prefix_sum.back();
        }


    }
};