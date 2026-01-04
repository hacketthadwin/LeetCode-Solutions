typedef vector<int> vi;

class Solution {
public:
void divisor(vi &div,int n){for(int i=1;i*i<=n;i++){if(n%i == 0){if(i == n/i)div.push_back(i);else{div.push_back(i);div.push_back(n/i);}}}}
    int sumFourDivisors(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            vector<int>divs;
            divisor(divs,nums[i]);
            if(divs.size()==4)
            {
                ans+=accumulate(divs.begin(),divs.end(),0);
            }
        }

        return ans;

    }
};