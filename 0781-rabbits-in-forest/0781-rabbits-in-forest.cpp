class Solution {
public:
    int numRabbits(vector<int>& ans) {
       if (ans.empty()) return 0;
        
        sort(ans.begin(), ans.end());
        int currnum = ans[0], cnt = 1, answer = 0;

        for (int i = 1; i < ans.size(); i++) {
            if (ans[i] == currnum && cnt < (currnum + 1)) {
                cnt++;
            } else {
                answer += (currnum + 1);
                currnum = ans[i]; 
                cnt = 1;
            }
        }
        answer += (currnum + 1);
        return answer;
    }
};