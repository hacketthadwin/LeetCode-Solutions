class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        vector<int>arr;
        int curr_num=nums[0];
        arr.push_back(curr_num);
        for(int i=1;i<n;i++)
        {
            if(nums[i]==curr_num)continue;
            curr_num=nums[i];
            arr.push_back(curr_num);
        }

        for(int i=1;i<arr.size()-1;i++)
        {
            if(arr[i]>arr[i+1] && arr[i]>arr[i-1])
            {
                count++;
            }
            else if(arr[i]<arr[i+1] && arr[i]<arr[i-1])
            {
                count++;
            }
        }
        return count;
    }
};
