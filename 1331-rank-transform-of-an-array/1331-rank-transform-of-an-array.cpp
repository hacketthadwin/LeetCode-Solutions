class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>sorted_arr=arr;
        sort(sorted_arr.begin(),sorted_arr.end());
        map<int,int>mp;
        int c=1;
        for(int i=0;i<arr.size();i++)
        {
            if(mp.count(sorted_arr[i]))continue;
            mp[sorted_arr[i]]=c;
            c++;
        }
        vector<int>ans;
        for(int i=0;i<arr.size();i++)
        {
            ans.push_back(mp[arr[i]]);
        }
        return ans;
    }
};