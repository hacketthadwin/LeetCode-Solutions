class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //so i can store count of each element..and will return k most frequent element
        //i can use unordered map for this....but to be solved using pq...need to think a bit...so it obviously...ok ok top k most frequent...so keep storing frequency of each element...then pick out top k...maps will do in O(nlog)..unordered map has average as O(1) but worst is O(n)...let it be avg
        unordered_map<int,int>freq;
        for(int i=0;i<nums.size();i++)
        {
            freq[nums[i]]++;
        }
        
        priority_queue<pair<int,int>>pq;
        for(auto m:freq)
        {
            pq.push({m.second,m.first});
        }
        vector<int>ans;
        while(k--)
        {
            int num=pq.top().second;
            pq.pop();
            ans.push_back(num);
        }
        return ans;
    }
};