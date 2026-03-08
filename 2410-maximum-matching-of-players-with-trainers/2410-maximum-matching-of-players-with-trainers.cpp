class Solution {
public:

    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        //my approach is i will populate this map with all the players, then for each player i will do lower bound to find the maximum index of trainer it can train from, then i will keep checking the players to find if they matched correctly or not with the player they can train from
        //as both are sorted, so after one player, no one can get trained because no trainer is available because player value is more than all trainer value, so after that we can cancel the process
        //
        int cnt=0;
        int min_indx_available=-1;
        for(int i=0;i<players.size();i++)
        {
            auto it = lower_bound(trainers.begin(),trainers.end(),players[i]);
            if(it!=trainers.end())
            {
                int indx=(it-trainers.begin());
                min_indx_available=max(min_indx_available+1,indx);
                if(min_indx_available<trainers.size())
                {
                    cnt++;
                }
                else
                {
                    break;
                }
            }
            else
            {
                break;
            }
        }

        return cnt;

    }
};