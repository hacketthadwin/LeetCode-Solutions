class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        // vector<int>v;
        int n=nums.size();
        // for(int i=0;i<nums.size();i++)
        // {
        //     v.push_back(nums[i]);
        // }
        // for(int i=0;i<nums.size();i++)
        // {
        //     v.push_back(nums[i]);
        // }
        //the size is already 2*nums.size()
        //now i have been given index as queries[i], so for counting i need to
        unordered_map<int, vector<int>>pos_num;

        for(int i=0;i<nums.size();i++)
        {
            pos_num[nums[i]].push_back(i);
        }

        // for(int i=0;i<pos_num.size();i++)
        // {
        //     if(pos_num[i].size()>1)pos_num[i].push_back(pos_num[i][0]+n);
        // }
        //  i don't think i need duplication, i can handle the circular using formula

        vector<int>ans;

        for(int i=0;i<queries.size();i++)
        {
            int indx=queries[i];
            int num=nums[indx];

            if(pos_num[num].size()<=1)
            {
                ans.push_back(-1);
                continue;
            }

            auto &vec = pos_num[num]; 

            auto it = lower_bound(vec.begin(),vec.end(),indx);
            int found_indx= (it-vec.begin());

            int mini=INT_MAX;

            // prev
            int prev_indx = (found_indx==0 ? vec.size()-1 : found_indx-1);
            int j = vec[prev_indx];
            int d = abs(j-indx);
            mini=min(mini,min(d,n-d)); 

            // next
            int next_indx = (found_indx==vec.size()-1 ? 0 : found_indx+1); 
            j = vec[next_indx];
            d = abs(j-indx);
            mini=min(mini,min(d,n-d)); 

            ans.push_back(mini);
        }

        return ans;
    }
};