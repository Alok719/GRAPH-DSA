class Solution {
public:
void dfs(int row,int col,vector<vector<int>>& image,int n,int m, int newColor,int initial,vector<int> &v1,vector<int> &v2){
    image[row][col]=newColor;
    for(int i=0;i<4;i++){
            int nrow=row+v1[i];
            int ncol=col+v2[i];
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m  && image[nrow][ncol]!=newColor && image[nrow][ncol]==initial){
                dfs(nrow,ncol,image,n,m,newColor,initial,v1,v2);
            }
        
    }
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here
    int n=image.size();int m=image[0].size();
     int initial=image[sr][sc];   
      vector<int> v1={-1,1,0,0};
    vector<int> v2={0,0,-1,1};
    dfs(sr,sc,image,n,m,newColor,initial,v1,v2);
    return image;
    }
};