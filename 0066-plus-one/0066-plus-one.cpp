class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>ans;
        //1249
        int prev=0;
        for(int i=digits.size()-1;i>=0;i++)
        {
            if(digits[i]==9)
            {
                //increase and break
                
                while(i>=0 && digits[i]==9)
                {
                    ans.push_back(0);
                    i--;
                }
                if(i>=0)
                {
                    ans.push_back(digits[i]+1);
                    i--;
                    while(i>=0)
                    {
                        ans.push_back(digits[i]);
                        i--;
                    }
                }
                else
                {
                    ans.push_back(1);
                }
                break;
            }
            else
            {
                //complete and break;
                ans.push_back(digits[i]+1);
                i--;
                while(i>=0)
                {
                    ans.push_back(digits[i]);
                    i--;
                }
                break;
            }

        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};