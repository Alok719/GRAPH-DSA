class Solution
{
public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {
        // code here
        vector<int> indeg(V + 1, 0);
        vector<int> revadj[V];
        vector<int> topo;
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                revadj[it].push_back(i);
                indeg[i]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < V; i++)
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
            for (auto it : revadj[node])
            {
                indeg[it]--;
                if (indeg[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        sort(topo.begin(), topo.end());
        return topo;
    }
};
