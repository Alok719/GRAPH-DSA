class Solution{
public:
    void dfs(int row,int col,int n,int m,vector<vector<char>> &mat,vector<vector<int>> &vis,vector<int> v1,vector<int> v2){
        vis[row][col]=1;
        for(int i=0;i<4;i++){
            int nrow=row+v1[i];
            int ncol=col+v2[i];
            if(ncol>=0 && ncol<m && nrow<n && nrow>=0 && !vis[nrow][ncol] && mat[nrow][ncol]=='O'){
                dfs(nrow,ncol,n,m,mat,vis,v1,v2);
            }
        }
        
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<int> v1={-1,1,0,0};
        vector<int> v2={0,0,-1,1};
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(mat[row][col]=='O' && !vis[row][col] && (row==0 || row==n-1 || col==0 || col==m-1)){
                    dfs(row,col,n,m,mat,vis,v1,v2);
                }
            }
        }
        vector<vector<char>> ans(mat.begin(),mat.end());
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(mat[row][col]=='O' && !vis[row][col]){
                    ans[row][col]='X';
                }
            }
        }
        return ans;
        
        
    }
};