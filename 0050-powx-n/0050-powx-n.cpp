class Solution {
public:
double rec(double x, int n)
{
    if(x==0)return 0;
    if(n==0)return 1.00000;
    double rec_soln=rec(x,n/2);
        double ans=1;
        if(n%2==0)
        {
            ans=rec_soln*rec_soln;
        }
        else
        {
            ans=rec_soln*rec_soln*x;
        }
        return ans;
}
    double myPow(double x, int n) {
        if(x==0)return 0;
        if(x==1)return 1;
        if(n==1)return x;
        if(n==0)return 1;
        double ans=1;
        double rec_soln=rec(x,n/2);
        if(n%2==0)
        {
            ans=rec_soln*rec_soln;
        }
        else
        {
            ans=rec_soln*rec_soln*x;
        }
        if(n<0)
        {
            return 1/ans;
        }
        return ans;
    }
};