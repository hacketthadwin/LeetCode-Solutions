class Solution {
public:
    // i could not solve this problem so i watched the solution
    // now the solution was like this that we will create a flips array which
    // will store the number of flips done till index i, that is number of flips
    // to be done on index i flips[i] denotes the flips that matter, flips[i-k]
    // is the flips that does not matter because it is outside the range of
    // sliding window we are only considering flips inside the sliding window
    // because we can only flip it inside the sliding window
    //odd flips, flips the current bit
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> flips(n, 0);
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                if ((i - k) >= 0) {
                    if ((flips[i - 1] - flips[i - k]) % 2 != 0) {
                        nums[i] = nums[i] ^ 1;
                    }
                } else {
                    if ((flips[i - 1] - 0) % 2 != 0) {
                        nums[i] = nums[i] ^ 1;
                    }
                }
            }
            if (nums[i] == 0) {
                if (i + k > n) {   //outside the range
                    return -1;
                }

                flips[i] = 1;   //add current flips
            }
            if (i > 0) {    //add previous flips
                flips[i] += flips[i - 1];
            }

            nums[i] = 1;   
        }
        return flips[n - 1];
    }
};