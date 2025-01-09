class Solution {
public:
//without memoisation,count variable was working 
//but after doing memoisation, count variable is another variable which will vary so it will not work with memoisation
//so the lesson is only use those states which are varying and try to keep the states low
vector<int>squares;
void squaring()
{
    int i=1;
    while((i*i)<=1e4)
    {
        squares.push_back((i*i));
        i++;
    }
}
int dp[100][10001];
int solve(int index,int sum,int n)
{

    //base case
    if(sum==n)return 0;
    //pruning case
    if(index>=squares.size())return 1e8;
    if(sum>n)return 1e8;
    //cache check
    if(dp[index][sum]!=-1)return dp[index][sum];
    //compute and transition
    int ans=min(
        1+solve(index,sum+squares[index],n),
        solve(index+1,sum,n));
    return dp[index][sum]=ans;
}
    int numSquares(int n) {
        squaring();
        memset(dp, -1, sizeof(dp));  
        return solve(0, 0, n);
    }
};