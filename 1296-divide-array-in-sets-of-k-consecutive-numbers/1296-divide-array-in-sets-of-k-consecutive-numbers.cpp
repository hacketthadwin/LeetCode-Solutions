class Solution {
public:
    bool isPossibleDivide(vector<int>& hand, int gsz) {
        if((hand.size()%gsz)!=0)return false;
        int cnt_groups=(hand.size()/gsz);
        sort(hand.begin(),hand.end());
        map<int,priority_queue<int,vector<int>,greater<int>>>mp;
        for(int i=0;i<hand.size();i++)
        {
            int el=hand[i];
            if(mp.count(el-1))
            {
                int sz=mp[el-1].top();
                if(sz<gsz)
                {
                    mp[el-1].pop();
                    if(mp[el-1].size()==0)mp.erase(el-1);
                    mp[el].push(sz+1); //considering i took el and joined it to the last number
                }
                else
                {
                    mp[el].push(1);
                }
            }
            else
            {
                mp[el].push(1);
            }
        }
        // debug(mp);
        // return 1;

        for(auto m:mp)
        {
            while(!m.second.empty())
            {
                if(m.second.top()!=gsz)
                {
                    return false;
                }
                m.second.pop();
            }
        }

        return true;
    }
};