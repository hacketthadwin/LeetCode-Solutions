class Solution {
public:
  vector<string> arr;

    int solve(string currstring, int idx) 
    {
        // Pruning case
        vector<int> charCount(26, 0); 
        for (char s : currstring) {
            if (charCount[s - 'a']++ > 0) return 0;
        }

        // Base case:
        if (idx == arr.size()) return currstring.size();
        //compute and transition
        int exclude = solve(currstring, idx + 1);                
        int include = solve(currstring + arr[idx], idx + 1);     
        return max(exclude, include);
    }
    int maxLength(vector<string>& arr1) {
        arr=arr1;
        int ans=solve("",0);
        return ans;
        
    }
};