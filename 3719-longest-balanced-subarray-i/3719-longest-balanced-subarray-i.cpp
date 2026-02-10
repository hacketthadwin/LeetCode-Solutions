class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        //what is want?
        //distinct number of odd numbers = distinct number of even numbers
        //for this what i can do is maintain a map,
        //i can  maintain a vector which will tell distinct odd till now, distinct even till now, nah this will not work
        // i tried thinking about map, but nah, i guess that will also not work, i want answer in o(n), so for that, i have to think differently
        //nahh not possible
        int maxi=0;
        for(int i=0;i<nums.size();i++)
        {
            unordered_map<int,int>odd,even;
            for(int j=i;j<nums.size();j++)
            {
                if(nums[j]%2==0)
                {
                    even[nums[j]]++;
                }
                else
                {
                    odd[nums[j]]++;
                }

                if(odd.size()==even.size())
                {
                    maxi=max(maxi,(j-i+1));
                }
            }
        }
        return maxi;
    }
};