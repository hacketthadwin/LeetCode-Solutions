class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>merged_intervals;
        int st=intervals[0][0];
        int end=intervals[0][1];
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]<=end)
            {
                //continous interval
                end=max(end,intervals[i][1]);
                st=min(st,intervals[i][0]);
            }
            else
            {
                //new break
                merged_intervals.push_back({st,end});
                st=intervals[i][0];
                end=intervals[i][1];
            }
        }
        merged_intervals.push_back({st,end});
        return merged_intervals;
    }
};