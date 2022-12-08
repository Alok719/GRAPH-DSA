class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool check(int node,int V,vector<int> adj[],vector<int> &vis,vector<int> &pvis){
        vis[node]=1;
        pvis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(check(it,V,adj,vis,pvis)==true) return true;
            }
            else if(pvis[it]==1) return true;
        }
        pvis[node]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V+1,0);
        vector<int> pvis(V+1,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(check(i,V,adj,vis,pvis)==true) return true;
            }
        }
        return false;
    }
};