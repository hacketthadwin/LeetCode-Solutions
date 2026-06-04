class Solution {
public:
int possible(int a)
{
    string t=to_string(a);
    if(t.size()<3)return 0;
    int ans=0;
    for(int i=1;i<t.size()-1;i++)
    {
        if(t[i]>t[i-1] && t[i]>t[i+1])ans++;
        if(t[i]<t[i-1] && t[i]<t[i+1])ans++;
    }
    return ans;

}
    int totalWaviness(int num1, int num2) {
        //for higher constraint, i would have solved it with digit dp, but my first approach will obviously be the brute force since it is just len(num2)*(num2-num1)
        int ans=0;
        for(int i=num1;i<=num2;i++)
        {
            ans+=possible(i);
        }
        return ans;
    }
};