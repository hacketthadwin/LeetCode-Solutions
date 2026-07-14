class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        vector<int>nums;
        for(auto c:s)
        {
            nums.push_back(c-'0');
        }

        vector<long long>prefix(nums.size());
        prefix[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            prefix[i]=prefix[i-1]+nums[i];
        }

        //i need a technique by which i can get integer from a range to another range 
        vector<int>last_digit_saw(nums.size());
        int last=-1;
        map<int,int>last_idx;

        string without_zeroes="";
        int j=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
            {
                last=i;
                last_idx[last]=j;
                without_zeroes+=s[i];
                j++;
            }
            last_digit_saw[i]=last;
        }
        //now i need to save the string for each of the combination of last
        // cout<<without_zeroes<<endl;

        long long mod=1e9+7;
        vector<long long> pref_val(without_zeroes.size()+1, 0);
        vector<long long> p10(without_zeroes.size()+1, 1);
        for(int i=0;i<without_zeroes.size();i++)
        {
            pref_val[i+1]=(pref_val[i]*10+(without_zeroes[i]-'0'))%mod;
            p10[i+1]=(p10[i]*10)%mod;
        }

        vector<int>next_digit_see(nums.size());
        int next=-1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(nums[i]!=0)
            {
                next=i;
            }
            next_digit_see[i]=next;
        }
        vector<int>ans;
        for(auto q:queries)
        {
            int l=q[0];
            int r=q[1];
            long long sum=prefix[r];
            if(l>0)
            {
                sum-=prefix[l-1];
            }
            int last_r=last_digit_saw[r];
            int next_l=next_digit_see[l];

            //now if last_r came -1...it means no non zero digit exist before r...it mean..we can simply put 0 in the answer
            //so 
            if(last_r==-1 || next_l==-1 || next_l>r || last_r<l)
            {
                ans.push_back(0);
                continue;
            }

            //otherwise just find the substring between them...infact not just between them...but last_idx[next_l] and last_idx[last_r];
            int non_zero_l=last_idx[next_l];
            int non_zero_r=last_idx[last_r];
            //now i just need the substring between these 
            //even though i will find the substring...as it is of length of 1e5...so this will give tle...as well as even if it didn't then i cannot convert that string to number without using modulo to first simplify
            //now i just need a substring between next_l and last_r;

            //ok so now sum is not the issue..the issue is extracting the string from l to r such that it doesn't contain any zeroes or something
            //i need to end at the digit which is non zero and exists before or at r
            //i need to start the digit which is non zero and exists after or at l
            
            int len=non_zero_r-non_zero_l+1;
            long long left_part=(pref_val[non_zero_l]*p10[len])%mod;
            long long x=(pref_val[non_zero_r+1]-left_part+mod)%mod;
            
            ans.push_back((x*(sum%mod))%mod);
        }

        return ans;
    }
};