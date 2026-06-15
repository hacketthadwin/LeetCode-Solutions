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
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size()==0)
        {
            return {newInterval};
        }
        vector<vector<int>>interval_pair;
        int cnt=0;
        if(newInterval[0]<intervals[0][0])
        {
            interval_pair.push_back({newInterval[0],newInterval[1]});
            cnt++;
        }
        for(int i=0;i<intervals.size();i++)
        {
            int interval1=intervals[i][0];
            int interval2=intervals[i][1];
            interval_pair.push_back({interval1,interval2});
            if(newInterval[0]>=interval1 && (i<(intervals.size()-1) ? newInterval[0]<=intervals[i+1][0] : true) && cnt<1)
            {
                interval_pair.push_back({newInterval[0],newInterval[1]});   
                cnt++;
            }
        }
        // return interval_pair;

        vector<vector<int>>ans=merge(interval_pair);
        return ans;
        

    }
};