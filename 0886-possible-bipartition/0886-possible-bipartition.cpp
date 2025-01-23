
class Solution {
public:
    // this is the exact same problem of is graph bipartite
    // so for that we only need to check if it is possible to divide the two groups based upon their liking or disliking
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adjlist(n);
        
        // Construct the adjacency list
        for (const auto& pair : dislikes) {
            int a = pair[0] - 1; // Convert to 0-based index
            int b = pair[1] - 1; // Convert to 0-based index
            adjlist[a].push_back(b);
            adjlist[b].push_back(a);
        }
        
        vector<int> visited(n, -1); // -1: not visited, 0: group A, 1: group B
        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (visited[i] == -1) {
                q.push(i);
                visited[i] = 0;

                while (!q.empty()) {
                    int u = q.front();
                    q.pop();

                    for (int v : adjlist[u]) {
                        if (visited[v] == -1) {
                            visited[v] = 1 - visited[u]; // Assign to the opposite group
                            q.push(v);
                        } else if (visited[v] == visited[u]) {
                            return false; // Conflict detected
                        }
                    }
                }
            }
        }

        return true;
    }
};
