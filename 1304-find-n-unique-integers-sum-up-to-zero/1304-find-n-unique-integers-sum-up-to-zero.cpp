class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>ans;
        for(int i=(-n/2);i<=(n/2);i++)
        {
            if(i==0)
            {
                if(n%2==1)ans.push_back(i);
            }
            else
            {
                ans.push_back(i); 
            } 
        }
        return ans;


    }
};