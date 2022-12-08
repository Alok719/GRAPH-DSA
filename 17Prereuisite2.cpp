class Solution
{
public:
    vector<int> findOrder(int N, int m, vector<vector<int>> pre)
    {
        // code here
        vector<int> topo;
        vector<int> indeg(N + 1, 0);
        queue<int> q;
        vector<int> adj[N];
        for (auto it : pre)
        {
            adj[it[1]].push_back(it[0]);
        }
        for (int i = 0; i < N; i++)
        {
            for (auto it : adj[i])
            {
                indeg[it]++;
            }
        }
        for (int i = 0; i < N; i++)
        {
            if (indeg[i] == 0)
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for (auto it : adj[node])
            {
                indeg[it]--;
                if (indeg[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        if (topo.size() == N)
        {
            return topo;
        }
        return {};
    };