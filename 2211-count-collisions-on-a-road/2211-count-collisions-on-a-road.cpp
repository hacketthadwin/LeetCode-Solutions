class Solution {
public:
    int countCollisions(string directions) {
        int right_to_left=0,stationary=0;
        int n=directions.size();
        int ans=0;
        
        for (int i=0;i<n;i++)
        {
            if (directions[i]=='R')
            {
                right_to_left++;
            }
            else if(directions[i]=='L')
            {
                if (right_to_left>0)
                {
                    ans += right_to_left + 1;
                    stationary++;
                    right_to_left = 0;
                }
                else if(stationary>0)
                {
                    ans++;
                }
            }
            else
            {
                if(right_to_left>0)
                {
                    ans+=right_to_left;
                    right_to_left=0;
                }
                stationary++;
            }
        }
        return ans;
    }
};