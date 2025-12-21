class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m=strs[0].size();
        int ans=0;

        // set<int>removed;
        // for(int i=0;i<n-1;i++)
        // {
        //     bool is_sorted=true;
        //     if(strs[i]>strs[i+1])
        //     {
        //         is_sorted=false;
        //     }

        //     if(!is_sorted)
        //     {
        //         //here we will compare which index to remove and will push that to set (if it isn't already)

        //     }
        // }

        // return s.size()

        //so after multiple attempts, i looked out to solution and found the approach like this (sound simple but my approach was completelely deviated from this one and therefore it is a good problem for me)

        //we need to calculate the number of deletions required, what is the most fundamental process you will follow?
        //if strs[i][j]>strs[i+1][j] , delete that index, simple?
        //now just make one more change in this that delete this only and only if the once we checked all previous indices and they are not sorted, if they are already sorted, don't delete it..simple
        //now let's code
        vector<bool>already_sorted(n-1,false);
        for(int j=0;j<m;j++)
        {
            bool deleted=false;
            for(int i=0;i<n-1;i++)
            {
                if(!already_sorted[i] && strs[i][j]>strs[i+1][j])
                {
                    deleted=true;
                    ans++;
                    break;
                }
            }
            if(deleted)continue;
            for(int i=0;i<n-1;i++)
            {
                already_sorted[i]=already_sorted[i]|(strs[i][j]<strs[i+1][j]);
            }
        }

        return ans;
    }
};
