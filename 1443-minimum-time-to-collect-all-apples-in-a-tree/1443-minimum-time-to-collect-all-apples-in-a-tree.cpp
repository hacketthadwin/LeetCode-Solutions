class Solution {
public:

    int ans = 0;

    int dfs(vector<vector<int>>& adj, vector<bool>& hasApple, int u, vector<bool>& visited) {
        visited[u] = true;
        int totalSteps = 0;

        for (int v : adj[u]) {
            if (!visited[v]) {
                int steps = dfs(adj, hasApple, v, visited);//steps denote that is there any apple in the subtree of the child
                if (steps > 0 || hasApple[v]) {
                    totalSteps += steps + 2; // Add 2 steps for going to and coming back from the child
                }
            }
        }

        return totalSteps;    //if no apples has been found then it will return 0
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);

        for (int i = 0; i < edges.size(); i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a); 
        }

        ans = dfs(adj, hasApple, 0, visited);
        return ans;
    }
};