class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=(int)gain.size();
        vector<int>al(n+1);
        al[0]=0;
        for(int i=1;i<al.size();i++)
        {
            al[i]=al[i-1]+gain[i-1];
        }

        return *max_element(al.begin(),al.end());
    }
};