// User function Template for C++

class Solution
{
public:
    bool dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &pvis, vector<int> &check)
    {
        vis[node] = 1;
        pvis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                if (dfs(it, adj, vis, pvis, check) == true)
                {
                    check[it] = 0;
                    return true;
                }
            }
            else if (pvis[it] && vis[it])
            {
                return true;
            }
        }
        check[node] = 1;
        pvis[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {
        // code here
        vector<int> vis(V + 1, 0);
        vector<int> pvis(V + 1, 0);
        vector<int> check(V + 1, 0);
        vector<int> ans;

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, adj, vis, pvis, check);
            }
        }
        for (int i = 0; i < V; i++)
        {
            if (check[i] == 1)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};