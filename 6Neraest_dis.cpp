class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n=grid.size();
	    int m=grid[0].size();
	    vector<vector<int>> vis(n,vector<int>(m,0));
	    vector<vector<int>> dis(n,vector<int>(m));
	    queue<pair<pair<int,int>,int>> q;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==1){
	                vis[i][j]=1;
	                q.push({{i,j},0});
	            }
	        }
	    }
	    vector<int> v1={-1,1,0,0};
	    vector<int> v2={0,0,-1,1};
	    while(!q.empty()){
	        int row=q.front().first.first;
	        int col=q.front().first.second;
	        int d=q.front().second;
	        dis[row][col]=d;
	        q.pop();
	        for(int i=0;i<4;i++){
	            int nrow=row+v1[i];
	            int ncol=col+v2[i];
	            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==0 && !vis[nrow][ncol]){
	                vis[nrow][ncol]=1;
	                q.push({{nrow,ncol},d+1});
	                
	            }
	        }
	        
	    }
	    return dis;
	}
};