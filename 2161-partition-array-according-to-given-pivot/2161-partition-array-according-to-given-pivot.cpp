class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>el_less_pivot,el_more_pivot,el_equal_pivot;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<pivot)
            {
                el_less_pivot.push_back(nums[i]);
            }
            
            if(nums[i]>pivot)
            {
                el_more_pivot.push_back(nums[i]);
            }

            if(nums[i]==pivot)
            {
                el_equal_pivot.push_back(nums[i]);
            }
        }

        vector<int>ans;
        for(int i=0;i<el_less_pivot.size();i++)
        {
            ans.push_back(el_less_pivot[i]);
        }
        for(int i=0;i<el_equal_pivot.size();i++)
        {
            ans.push_back(el_equal_pivot[i]);
        }
        for(int i=0;i<el_more_pivot.size();i++)
        {
            ans.push_back(el_more_pivot[i]);
        }
        return ans;
    }
};