class Solution {
public:
    bool toposortindfs(int node, vector<vector<int>>& adjlist, vector<int>& ans, vector<int>& visited) {
        visited[node] = 1; // visiting

        for (int nei : adjlist[node]) {
            if (visited[nei] == 1) return false; // cycle
            if (visited[nei] == 0) {
                if (!toposortindfs(nei, adjlist, ans, visited)) return false;
            }
        }

        visited[node] = 2; // visited
        ans.push_back(node);
        return true;
    }

    vector<int> toposortindfssolver(int v, vector<vector<int>>& adjlist) {
        vector<int> visited(v, 0);
        vector<int> ans;

        for (int i = 0; i < v; i++) {
            if (visited[i] == 0) {
                if (!toposortindfs(i, adjlist, ans, visited)) return {}; // cycle detected
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& row, vector<vector<int>>& col) {

        vector<vector<int>> adj_row(k), adj_col(k);

        for (auto &r : row) {
            adj_row[r[0] - 1].push_back(r[1] - 1);
        }
        for (auto &c : col) {
            adj_col[c[0] - 1].push_back(c[1] - 1);
        }

        vector<int> ans_row = toposortindfssolver(k, adj_row);
        vector<int> ans_col = toposortindfssolver(k, adj_col);

        if (ans_row.empty() || ans_col.empty()) return {}; 

        vector<pair<int,int>> positions(k, {-1, -1});

        for (int i = 0; i < k; i++) {
            positions[ans_row[i]].first = i;  
        }
        for (int i = 0; i < k; i++) {
            positions[ans_col[i]].second = i;
        }

        vector<vector<int>> ans(k, vector<int>(k, 0));

        for (int i = 0; i < k; i++) {
            if (positions[i].first == -1 || positions[i].second == -1) return {};
            ans[positions[i].first][positions[i].second] = i + 1;
        }

        return ans;



    }
};