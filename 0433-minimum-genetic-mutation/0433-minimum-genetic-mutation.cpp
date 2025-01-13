class Solution {
public:
    // this is classic bfs problem
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> bankers(bank.begin(), bank.end());
        queue<string> q;
        q.push(start);
        int level = 0;
        unordered_set<string> visited;
        visited.insert(start);
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                string curr = q.front();
                q.pop();
                if (curr == end)
                    return level;
                for (auto c : "ATCG") {
                    for (int i = 0; i < curr.size(); i++) {
                        string original = curr;
                        original[i] = c;
                        if (visited.find(original) == visited.end() &&
                            bankers.find(original) != bankers.end()) {
                            visited.insert(original);
                            q.push(original);
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};