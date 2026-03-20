class Solution {
public:
bool f(int m, vector<int>& dist, double hour)
{
    //now i will just compute the time with the speed and if the time is more than hour, then sorry , but it's not possible
    double check_hour=0;
    for(int i=0;i<dist.size();i++)
    {
        double curr = (double)dist[i]/m;
        if(i==(dist.size()-1))
        {
            check_hour+=curr;
        }
        else
        {
            check_hour+= ceil(curr);
        }
        if(check_hour>hour)
        {
            return false;
        }
    }
    return true;
}
    int minSpeedOnTime(vector<int>& dist, double hour) {
        //here speed will be the invariant
        int l=0,r=INT_MAX;
        while(r-l>1)
        {
            int m=(l+((r-l)/2));
            if(f(m,dist,hour))
            {
                r=m;
            }
            else
            {
                l=m;
            }
        }
        if(r==INT_MAX)
        {
            return -1;
        }
        return r;
    }
};