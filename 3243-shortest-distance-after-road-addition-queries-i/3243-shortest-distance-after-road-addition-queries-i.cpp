class Solution {
public:
     int rec(int n, vector<vector<pair<int, int>>>& adj) {
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto i : adj[u]) {
            int v = i.first;
            int weight = i.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
         if (u == n - 1) break;
    }

    return dist[n - 1];
}
 
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
         vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < n - 1; ++i) 
            adj[i].push_back({i + 1, 1});

        vector<int>ans;
        for (auto i: queries) {
            int u = i[0];
            int v = i[1];
            adj[u].push_back({v, 1});
            ans.push_back(rec(n, adj));
        }
        return ans;
    }
};