class Solution
{
public:
    vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
    {
        // code here
        vector<int> adj[N];
        vector<int> vis(N + 1, 0);
        queue<pair<int, int>> q;
        for (auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> dis(N, 1e9);
        dis[src] = 0;
        q.push({src, 0});
        while (!q.empty())
        {
            int node = q.front().first;
            int d = q.front().second;
            q.pop();
            for (auto it : adj[node])
            {
                if (d + 1 < dis[it])
                {
                    dis[it] = d + 1;
                    q.push({it, dis[it]});
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