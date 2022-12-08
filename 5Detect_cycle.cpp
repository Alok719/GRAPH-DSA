class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    // bool detectcycle(int src,vector<int> adj[],vector<int> &vis){
    //     queue<pair<int,int>> q;
    //     q.push({src,-1});
    //     vis[src]=1;
    //     while(!q.empty()){
    //         int node=q.front().first;
    //         int parent=q.front().second;
    //         q.pop();
    //         for(auto adjacentnode: adj[node]){
    //             if(!vis[adjacentnode]){
    //                 vis[adjacentnode]=1;
    //                 q.push({adjacentnode,node});
    //             }
    //             else if(parent!=adjacentnode){
    //                 return true;
    //             }
    //         }
    //     }
    //     return false;
    // }
    bool bfscycle(int node,int parent,vector<int> adj[],vector<int> &vis){
        vis[node]=1;
        for(auto adjnode:adj[node]){
            if(!vis[adjnode]){
                if(bfscycle(adjnode,node,adj,vis)==true){
                    return true;
                }
            }
            else if(parent!=adjnode){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(bfscycle(i,-1,adj,vis)==true){
                    return true;
                }
            }
        }
        return false;
        
    }
};