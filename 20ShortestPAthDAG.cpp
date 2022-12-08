class Solution
{
    void topo(int node, vector<int> &vis, vector<pair<int, int>> adj[], stack<int> &st)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            int v = it.first;
            if (!vis[v])
            {

                topo(v, vis, adj, st);
            }
        }
        st.push(node);
    }

public:
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        // code here
        vector<pair<int, int>> adj[N];
        vector<int> vis(N + 1, 0);
        stack<int> st;
        vector<int> dis(N, 1e9);
        for (int i = 0; i < M; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }
        for (int i = 0; i < N; i++)
        {
            if (!vis[i])
            {
                topo(i, vis, adj, st);
            }
        }
        dis[0] = 0;
        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            for (auto it : adj[node])
            {
                int v = it.first;
                int wt = it.second;
                if (dis[node] + wt < dis[v])
                {
                    dis[v] = dis[node] + wt;
                }
            }
        }
        for (int i = 0; i < N; i++)
        {
            if (dis[i] == 1e9)
            {
                dis[i] = -1;
            }
        }
        return dis;
    }
};