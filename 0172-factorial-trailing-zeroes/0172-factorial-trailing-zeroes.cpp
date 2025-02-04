class Solution {
public:
    int trailingZeroes(int n) {
        int k=5;
        int c=n/k;
        int ans=0;
        while(c!=0)
        {
            ans+=c;
            k*=5;
            c=n/k;
        }
        return ans;
    }
};