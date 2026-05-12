class Solution {
public:
bool check(int m,vector<pair<int,pair<int,int>>>&v)
{
    for(int i=0;i<v.size();i++)
    {
        if(v[i].second.first<=m)
        {
            m-=v[i].second.second;
        }
        else
        {
            return false;
        }
    }

    return true;

}
    int minimumEffort(vector<vector<int>>& tasks) {
        vector<pair<int,pair<int,int>>>v;
        for(int i=0;i<tasks.size();i++)
        {
            v.push_back({abs(tasks[i][1]-tasks[i][0]),{tasks[i][1],tasks[i][0]}});
        }
        sort(v.rbegin(),v.rend());
        int l=0,r=1e9,m;
        while(r-l>1)
        {
            m=l+(r-l)/2;
            if(check(m,v))
            {
                r=m;
            }
            else
            {
                l=m;
            }
        }
        return r;
    }
};