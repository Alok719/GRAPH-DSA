class Solution
{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        // Code here
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dis(n + 1, 1e9);
        vector<int> parent(n + 1);
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;

        }
        vector<pair<int, int>> adj[n + 1];
        for (int i = 0; i < m; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        // for(auto it:edges){
        //     adj[it[0]].push_back({it[1],it[2]});
        //     adj[it[1]].push_back({it[0],it[2]});
        // }
        dis[1] = 0;
        pq.push({0, 1});
        while (!pq.empty())
        {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto it : adj[node])
            {
                int wt = it.second;
                int adjnode = it.first;
                if (dist + wt < dis[adjnode])
                {
                    dis[adjnode] = dist + wt;
                    pq.push({dis[adjnode], adjnode});
                    parent[adjnode] = node;
                }
            }
        }
        int node = n;
        vector<int> ans;
        while (parent[node] != node)
        {
            ans.push_back(node);
            node = parent[node];
        }
        ans.push_back(1);
        reverse(ans.begin(), ans.end());
        if (dis[n] == 1e9)
        {

            return {-1};
        }
        return ans;
    }
};