class Solution
{
public:
    vector<int> topoSort(int V, vector<int> adj[])
    {
        // code here
        vector<int> indeg(V + 1, 0);
        vector<int> topo;
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {

                indeg[it]++;
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
            for (auto it : adj[node])
            {
                indeg[it]--;
                if (indeg[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        return topo;
    }
    string findOrder(string dict[], int N, int K)
    {
        // code here
        vector<int> adj[K];
        for (int i = 0; i < N - 1; i++)
        {
            string s1 = dict[i];
            string s2 = dict[i + 1];
            int len = min(s1.size(), s2.size());
            for (int ptr = 0; ptr < len; ptr++)
            {
                if (s1[ptr] != s2[ptr])
                {
                    adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                    break;
                }
            }
        }
        vector<int> topo = topoSort(K, adj);
        string s = "";
        for (auto it : topo)
        {
            s.push_back(it + 'a');
        }

        return s;
    }
};