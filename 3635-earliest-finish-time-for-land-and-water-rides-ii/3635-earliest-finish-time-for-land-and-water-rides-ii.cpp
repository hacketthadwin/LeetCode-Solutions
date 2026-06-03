class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
                 int n = landStartTime.size();
        int m = waterStartTime.size();
        vector<int> land_time(n), water_time(m);
        for (int i = 0; i < n; i++)
            land_time[i] = landStartTime[i] + landDuration[i];
        for (int i = 0; i < m; i++)
            water_time[i] = waterStartTime[i] + waterDuration[i];

        int least_time_taken_by_land  = *min_element(land_time.begin(),  land_time.end());
        int least_time_taken_by_water = *min_element(water_time.begin(), water_time.end());
        int ans = INT_MAX;

        for (int i = 0; i < m; i++) {
            int finish = max(least_time_taken_by_land, waterStartTime[i]) + waterDuration[i];
            ans = min(ans, finish);
        }
        for (int i = 0; i < n; i++) {
            int finish = max(least_time_taken_by_water, landStartTime[i]) + landDuration[i];
            ans = min(ans, finish);
        }
        return ans;
    }
};