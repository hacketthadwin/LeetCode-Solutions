class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long curr_mass=(long long)mass;
        sort(asteroids.begin(),asteroids.end());
        for(int i=0;i<asteroids.size();i++)
        {
            if(curr_mass>=asteroids[i])
            {
                curr_mass+=asteroids[i];
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};