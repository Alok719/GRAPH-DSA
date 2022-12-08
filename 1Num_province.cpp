class Solution {
  public:
  void dfs(vector<int> adj[], int V,vector<int> &vis,int node){
      vis[node]=1;
      for(auto it:adj[node]){
          if(!vis[it]){
              vis[it]=1;
              dfs(adj,V,vis,it);
          }
      }
  }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int> vis(V+1,0);
        int ans=0;
        vector<int> ad[V+1];
        int n=adj.size();
        int m=adj[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(adj[i][j]==1){
                 ad[i+1].push_back(j+1);
                //  ad[j+1].push_back(i+1);

                }
            }
        }
        for(int i=1;i<=V;i++){
            if(!vis[i]){
                dfs(ad,V,vis,i);
            ans++;
            }
        }
        return ans;
        
    }
};