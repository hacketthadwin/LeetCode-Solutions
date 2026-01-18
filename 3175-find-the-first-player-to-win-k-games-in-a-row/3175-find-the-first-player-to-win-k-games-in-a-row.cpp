class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        vector<int>wins(skills.size());
        int maxi=*max_element(skills.begin(),skills.end());
        int i=0;
        int j=1;
        int curr=skills[0];
        int curr_indx=0;
        for(int i=1;i<skills.size()-1;i++)
        {
            if(curr>skills[i])
            {
                //i will choose curr
                wins[curr_indx]++;
            }
            else
            {
                curr=skills[i];
                curr_indx=i;
                wins[curr_indx]++;
            }

            if(wins[curr_indx]==k)
            {
                return curr_indx;
            }
        }

        return (max_element(skills.begin(),skills.end())-skills.begin());

    }
};