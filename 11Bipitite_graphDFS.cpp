class Solution {
public:

bool check(int i,int V,vector<int>adj[],vector<int> &vis){
     
    for(auto it:adj[i]){
        if(vis[it]==-1){
           if(vis[i]==0){
                vis[it]=1;
            }
            else vis[it]=0;
            if(check(it,V,adj,vis)==false) return false;
        }
        else if(vis[it]==vis[i]){
            return false;
        }
        
    }
    return true;
}

	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> vis(V+1,-1);
	    for(int i=0;i<V;i++){
	        if(vis[i]==-1){
	            vis[i]=0;
	        if(check(i,V,adj,vis)==false){
	            return false;
	        }
	        }
	    }
	    return true;
	    
	}

};