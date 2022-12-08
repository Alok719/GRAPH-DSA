class Solution {
  public:
//   void dfs(int row,int col,vector<vector<int>> &grid,vector<vector<int>> &vis,vector<int> v1,vector<int> v2,int n,int m){
//       vis[row][col]=1;
//       for(int i=0;i<4;i++){
//           int nrow=row+v1[i];
//           int ncol=col+v2[i];
//           if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
//               dfs(nrow,ncol,grid,vis,v1,v2,n,m);
//           }
//       }
//   }

  int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        vector<int> v1={-1,1,0,0};
        vector<int> v2={0,0,-1,1};
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans=0;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && (i==0 || i==n-1 || j==0 || j==m-1)){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int row=q.front().first;
      int col=q.front().second;
      vis[row][col]=1;
      q.pop();
      for(int i=0;i<4;i++){
          int nrow=row+v1[i];
          int ncol=col+v2[i];
          if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
              q.push({nrow,ncol});
              
          }
      }
        }
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    ans++;
                }
            }
        }
        return ans;
    
    }
    
};