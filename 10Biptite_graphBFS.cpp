class Solution {
public:
bool check(int i,int V,vector<int>adj[],vector<int> &vis){
    queue<int> q;
	    q.push(i);
	    vis[i]=0;
	    while(!q.empty()){
	        int node=q.front();q.pop();
	        for(auto it:adj[node]){
	            if(vis[it]==-1){
	                if(vis[node]==0){
	                    vis[it]=1;
	                }
	                else vis[it]=0;
	                q.push(it);
	            }
	            else if( vis[it]==vis[node]){
	                return false;
	            }
	        }
	    }
	    return true;
}
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> vis(V+1,-1);
	    for(int i=0;i<V;i++){
	        if(vis[i]==-1){
	        if(check(i,V,adj,vis)==false){
	            return false;
	        }
	        }
	    }
	    return true;
	    
	}

};