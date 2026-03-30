class Solution {
public:
int f(int m, int n, vector<int>& quantities)
{
    //so here we have been given x as m, 
    //so n stores, m type of product, and i need to distribute all of them, so consider if i first give m products to every store,
    //now the maximum product each store can have is currently m, so we will not give any store product more than m
    //now i will start giving the stores m products, if i see that all products end, then good, if some products are left, it means return false
    //so each product will be given to ceel(quantities/m) stores , so i guess the formula for that is (quantites+m-1/m);
    if(m==0)return false;
    for(int i=0;i<quantities.size();i++)
    {
        int curr= ((quantities[i]+m-1)/m);
        n-=curr;
        if(n<0)return false; //this is because i need 4 stores to distribute 10 products with m=3, but consider if i have n=3 i.e 3 stores, then n <0 which is impossible case, that's why return false
    }
    return true;


}
    int minimizedMaximum(int n, vector<int>& quantities) {
        // so i need to find x which is maximum number of products given to any store such that we can minimise the value of x
        //so basically we need to minimise the x, so it will be minimising concpt
        //i will take x as m and then i will try to decrease the value of m
        int l=0, r=1e9;
        while((r-l)>1)
        {
            int m= (l+((r-l)/2));
            if(f(m,n,quantities))
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