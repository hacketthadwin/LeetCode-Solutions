class Solution {
public:
    bool f(int m,vector<int>& weights, int days)
    {
        //now i have been given the weight capacity, i think i will need a prefix array here, ok so first i will create a prefix array
        //now i will do lower bound to find the first value, then the second value, then the third value and so on, if m is correct, then i should be able to send all the packages to the , also as it is prefix array, so we know its always sorted
        //ok i overcomplicated a simple problem, i can just sum the weights and if it exceeds m, i will increase the days, after all i have to check with days only, in my previous approach, i didn't even took days in consideration, so that is completely wrong
        int curr_days=1;
        int curr_weight=0;
        for(int i=0;i<weights.size();i++)
        {
            if (weights[i] > m) return false;
            //now why do we needed to add this if (weights[i] > m) return false; check?
            //it is because i was using l=0 and only if((weights[i]+curr_weight)>m) was not enough because
            //If weights[i] > m, the condition (weights[i] + curr_weight) > m triggers a day increment, 
            //but curr_weight is then assigned a value that already violates the capacity m, 
            //causing the simulation to bypass the capacity constraint for that specific element.
            //basically, the above condition is a The "Defensive" Check Function i.e. if we want to become boundless, i.e. no specific bounds
            //then we must explicitly handle the "impossible" case inside f
            //remember this
            if((weights[i]+curr_weight)>m)
            {
                curr_days++;
                curr_weight=weights[i];
            }
            else
            {
                curr_weight+=weights[i];
            }
            if(curr_days>days)return false;
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        //the invariant is weight capacity
        int l=0,r=INT_MAX;
        while((r-l)>1)
        {
            int m = (l+((r-l)/2));
            if(f(m,weights,days))
            {
                r=m;
            }
            else
            {
                l=m;
            }
        }
        return r;
    }
};