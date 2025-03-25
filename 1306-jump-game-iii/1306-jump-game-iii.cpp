class Solution {
public:
      vector<int> dp;
    bool rec(int index, vector<int>& arr,int n)
    {
        //pruning case
        if(index>=n || index<0 || dp[index]==0)
        {
            return false;
        }
        //base case
        if(arr[index]==0)return true;
        // cache check
        if(dp[index]!=-1)return dp[index];
        //compute and transtion
        dp[index] = 0;  //this is the most important step, this step is used to check that we have visited this index and don't need to visit again and if we visit again then it means that it is not possible to visit to 0 with this process hence we return dp[index]==0 in the pruning case and the recursion will break (awesome approach)
        dp[index]= rec(index+arr[index],arr,n) || rec(index-arr[index],arr,n);
        
        return dp[index];

    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        dp.resize(n, -1);
        return rec(start,arr,n);
    }
};