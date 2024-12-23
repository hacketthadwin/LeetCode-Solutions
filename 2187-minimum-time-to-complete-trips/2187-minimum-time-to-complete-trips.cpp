class Solution {
public:
bool check(long long n,long long mid, vector<int>& arr, int totalTrips) {
    long long trips = 0;
    for (int t : arr) {
        long long int val = t;
        trips += (mid / val); 
        if (trips >=totalTrips) return true; 
    }
    return false;
}
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long int n=time.size();
        long long int lo=1;
        long long int hi=1e12;
        while((hi-lo)>1)
        {
            long long int mid=(lo+((hi-lo)/2));
            if(check(n,mid,time,totalTrips))
            {
                hi=mid;

            }
            else
            {
                lo=mid;
            }
        }
        if(check(n,lo,time,totalTrips))return lo;
        else return hi;
    }

};