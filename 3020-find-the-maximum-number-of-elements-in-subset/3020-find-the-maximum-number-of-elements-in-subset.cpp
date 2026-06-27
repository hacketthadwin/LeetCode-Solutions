class Solution {
public:
    int maximumLength(vector<int>& nums) {
        //so basically it should be low to high to low but in exponents of a base number decided by us
        //we can decide any number..and then check about its exponents
        //also remember..that there must be 1 highest number

        map<long long,int>is_present;
        for(int i=0;i<nums.size();i++)
        {
            is_present[nums[i]]++;
        }
        int cnt=1;
        for(auto p:is_present)
        {
            long long num=p.first;
            int copy_num=num;
            int cnti=p.second;
            int temp_cnt=0;
            if(cnti==1 || num==1)
            {
                temp_cnt=cnti;
            }
            else
            {
                for(int i=1;num<=1e9;i++)
                {
                    if(is_present.count(num))
                    {
                        //i can only take 2 numbers from here...so i will take both..
                        temp_cnt+=min(is_present[num],2);
                        if(is_present[num]==1)break;
                        num*=num;
                        if(!is_present.count(num))break;
                    }
                    else break;
                    
                }
            }
            cnt=max(cnt,temp_cnt%2==1? temp_cnt: (temp_cnt-1));
        }
        return cnt;
    }
};