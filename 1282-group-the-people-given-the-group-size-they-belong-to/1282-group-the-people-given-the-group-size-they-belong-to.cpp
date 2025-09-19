class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& g) {
                int n=g.size();
        vector<pair<int,int>>arr(n);
        for(int i=0;i<n;i++){
            arr[i]={g[i],i};
        }
        sort(arr.begin(),arr.end());
        vector<vector<int>>res;
        int i=0;
        while(i<n){
            int group_size=arr[i].first;
            vector<int>asf(group_size);
            for(int j=i;j<i+group_size;j++){
                int ele=arr[j].second;
                asf[j-i]=ele;
            }
            res.push_back(asf);
            i+=group_size;
        }
        return res;

    }
};