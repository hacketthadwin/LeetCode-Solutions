class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> all_paths;  // Store all possible paths
        queue<vector<int>> q;  // Queue to store paths during BFS
        int target = graph.size() - 1;  // Target node (n-1)
        
        q.push({0});  // Start BFS from node 0

        while (!q.empty()) {
            vector<int> path = q.front();
            q.pop();

            int last_node = path.back();

            // If we reached the target, store the path
            if (last_node == target) {
                all_paths.push_back(path);
            }

            // Explore neighbors
            for (int neighbor : graph[last_node]) {
                vector<int> new_path = path;
                new_path.push_back(neighbor);
                q.push(new_path);
            }
        }

        return all_paths;
    }
};
