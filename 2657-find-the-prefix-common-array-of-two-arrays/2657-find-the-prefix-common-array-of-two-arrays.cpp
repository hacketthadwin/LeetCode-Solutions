class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        map<int,int>mp;
        vector<int>v(51,0);
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            mp[A[i]]++;
            mp[B[i]]++;
            // i+1 is size, and mp.size is total size till now, 
            ans.push_back((2*(i+1))-mp.size());
        }
        return ans;


        
    }
};