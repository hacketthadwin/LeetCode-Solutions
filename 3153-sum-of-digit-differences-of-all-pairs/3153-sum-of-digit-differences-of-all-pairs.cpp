class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int curr = nums[0];
        int p = 0;
        while (curr > 0) {
            p++;
            curr /= 10;
        }

        vector<vector<int>> v(p);

        for (int i = 0; i < nums.size(); i++) 
        {
            int curr = nums[i];
            int j = 0;
            while (curr > 0) 
            {
                v[j].push_back(curr % 10);
                curr /= 10;
                j++;
            }
        }

        long long ans=0;
        //v is a vector of size= len of number ok?
        //now each vector v[i] stores the values at index i in each number
        //we have count the different values , so i will keep a frequency map of each number then i will multiply all different numbers with that frequency map -> the combinatorics method of counting different values
        //SO ALWAYS REMEMBER THIS MENTAL MODEL
        for(int i=0;i<v.size();i++)
        {
            map<int,int>mp;
            for(int j=0;j<v[i].size();j++)
            {
                mp[v[i][j]]++;
            }
            vector<int>vals;
            if(mp.size()>1)
            {
                for(auto m:mp)
                {  
                    vals.push_back(m.second);
                }

                for(int m=0;m<vals.size();m++)
                {
                    for(int n=m+1;n<vals.size();n++)
                    {
                        ans+=(long long)vals[m]*vals[n];
                    }
                }
            }
            
        }

        return ans;
    }
};