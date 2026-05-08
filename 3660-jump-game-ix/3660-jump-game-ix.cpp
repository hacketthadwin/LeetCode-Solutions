class Solution {
public:
//understand this, mere value se jyada value wale ke paas sirf peeche jaa skte, aage jaane ka mtlb hai...apne se kam value pe jump kr rhe
//so kya kya observation mila....minimum value wale index se pehle jo bhi maximum hai...
//but wait, minimum pe focus krna galat tha
//actual observation ye hai ki agar left side ka koi bhi maximum
//right side ke kisi bhi minimum se bada hai
//toh dono segments merge ho jayenge
//because left -> right possible and then right -> left possible
//so instead of solving per index, solve per segment
    vector<int> maxValue(vector<int>& nums) {
        int n=nums.size();

        //this will iterate from 0 to n
        vector<int>max_till_now(nums.size());

        //this will iterate from n to 0
        vector<int>min_from_now(nums.size());

        max_till_now[0]=0;
        min_from_now[n-1]=n-1;

        for(int i=1;i<n;i++)
        {
            // max_till_now[i]=max(max_till_now[i],max_till_now[i-1]);

            if(nums[i]>nums[max_till_now[i-1]])
            {
                max_till_now[i]=i;
            }
            else
            {
                max_till_now[i]=max_till_now[i-1];
            }
        }

        for(int i=n-2;i>=0;i--)
        {
            // min_from_now[n-1-i]=max(min_from_now[n-1-i],min_from_now[(n-1-i)-1]);

            if(nums[i]<nums[min_from_now[i+1]])
            {
                min_from_now[i]=i;
            }
            else
            {
                min_from_now[i]=min_from_now[i+1];
            }
        }

        vector<int>ans(nums.size());

        //last element ka answer obviously uske prefix max ke equal hoga
        ans[n-1]=nums[max_till_now[n-1]];

        //right se iterate kro because merge future segment se hoga
        for(int i=n-2;i>=0;i--)
        {
            //IMPORTANT OBSERVATION
            //agar left side ka maximum > right side ka minimum
            //then dono segments connected hai
            if(nums[max_till_now[i]]>nums[min_from_now[i+1]])
            {
                //same segment ka part hai
                ans[i]=ans[i+1];
            }
            else
            {
                //new segment start hua
                ans[i]=nums[max_till_now[i]];
            }
        }
        return ans;
    }
};