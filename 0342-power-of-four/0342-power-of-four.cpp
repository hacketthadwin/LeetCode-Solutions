class Solution {
public:
//1 0 1 0 1 0 1 0 1 
    bool isPowerOfFour(int n) {
        int cnt = __builtin_popcount(n);
        if(cnt==1)
        {
            for(int i=0;i<31;i+=2)
            {
                if(n&(1<<i))
                {
                    return true;
                }
            }
            return false;
        }
        else
        {
            return false;
        }
    }
};