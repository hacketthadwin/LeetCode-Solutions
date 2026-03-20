class Solution {
public:
bool f(long long mid, vector<int>& ranks, long long cars)
{
    //now we want to check if it is possible to make the simulataneous decision such that we can achieve the total time less than mid or not
    //i will have to assign few number of cars to all the things, such that all cars must get divided into each other properly
    //ok so mid is the time, and time is calculated from rank and that formula gives the number of cars, then why can't we find the total cars that can be accomodated and once that number of cars exceed our number of cars, we can say that it is possible, if we complete whole array and still that number of cars is not reached, then it is not possible, easy boy
    long long curr_cars=0;
    for(int i=0;i<ranks.size();i++)
    {
        long long thing = (mid/ranks[i]);
        curr_cars+= sqrt(thing);
        if(curr_cars>=cars)return true;
    }
    return false;

}
    long long repairCars(vector<int>& ranks, int cars) {
        //so what are we given with
        //there are n cars, given the ranks of each mechanic, each mechanic can repair car in r*n^2 minutes, we want to do it as soon as possible
        //all can do simulataneously, so the lowest ranked mechanic can do faster than any
        //now our invariant will be the time, in the binary search code, we will take the mid as the time taken to do it and then we will calculate if it is possible to do it in that time or not, if it is possible, then r = mid, else l = mid, i guess we are pretty good to go now, let's write the code
        sort(ranks.begin(),ranks.end());
        long long l=0, r=LLONG_MAX;
        while(r-l>1)
        {
            long long mid = ((r+l)/2);
            if(f(mid,ranks,cars))
            {
                r=mid;
            }
            else
            {
                l=mid;
            }
        }

        return r;
    }
};