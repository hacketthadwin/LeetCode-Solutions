class Solution {
public:
    vector<int> nextGreaterElements(vector<int>&nums) {
        deque<int>dq;
        vector<int>ans(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            int c=i%(nums.size());

            if(!dq.empty() && nums[dq.back()]>nums[c])
            {
                int temp=dq.back();
                while(!dq.empty() && nums[dq.back()]>nums[c])
                {
                    temp=dq.back();
                    dq.pop_back();
                }
                ans[i%(nums.size())]=temp;
                
            }
            else
            {
                ans[i%(nums.size())]=-1;
            }
           if(dq.empty() || nums[c]>nums[dq.back()] ) dq.push_back(c);
        }

        return ans;
    }
    int nextGreaterElement(int n) {
        vector<int>el;
        int val=10;
        int temp=n;
        while(n>0)
        {
            el.push_back(n%val);
            n/=10;
        }
        //now i just need to make a number bigger than this...so what i can do is...
        //so i will just iterate through the el vector and if i find any number which was bigger before but now it is less than that number...i will just replace those 2 integers and boom got my answer
       vector<int>check=nextGreaterElements(el);
        int swap_idx=-1;
        for(int i=0;i<check.size();i++)
        {
            if(check[i]!=-1)
            {
                swap_idx=i;
                swap(el[check[i]],el[i]);
                break;
            }
        }
        // for (int x : el)
        //     cout << x << ' ';
        // cout << endl;

        // for (int x : check)
        //     cout << x << ' ';
        // cout << endl;
        if(swap_idx==-1)return -1;

        //otherwise i will make all elements before i small
        //like i will sort it

        sort(el.rend()-swap_idx,el.rend());
        long long ans=0;
        long long temp_val=1;
        for(int i=0;i<el.size();i++)
        {
            ans+=(el[i]*temp_val);
            temp_val*=10;
        }
        cout<<ans<<endl;
        if(ans>INT_MAX || ans<=temp)
        {
            return -1;
        }
        return ans;
    }
};