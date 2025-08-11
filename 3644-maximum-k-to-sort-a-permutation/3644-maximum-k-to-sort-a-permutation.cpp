class Solution {
public:
// The solution works by leveraging bitwise properties to determine the maximum k enabling swaps to sort the array:
// since swaps are allowed only if nums[i] & nums[j] == k, 
//k must be a subset of the bits of every out-of-place element,
// making the bitwise AND of all such elements (k0) the maximal valid k—any larger k would exclude at least one element, breaking swap connectivity. 
//If the array is sorted (k0 = INT_MAX),
// k = 0 suffices, as no swaps are needed. 
//This approach ensures that all out-of-place elements can participate in swaps (as x & y ≥ k0 holds for any pair), 
//allowing the array to be sorted through direct or intermediate swaps,
// and it efficiently computes k0 in linear time by iterating through the array and accumulating the AND of mismatched elements. 
//Similar problems involve bitmask-based constraints on swaps or partitions.


    int sortPermutation(vector<int>& nums) {
        int n=nums.size();
        int k=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=(i))
            {
                k&=nums[i];
            }
        }
        return k==INT_MAX ? 0 : k;

    }
};