class Solution {
public:
int delrow[4]={0,-1,0,+1};
int delcol[4]={-1,0,+1,0};
    int numEnclaves(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int count=0;

        
        for(int i=0;i<m;i++){
            //first row
            if(grid[0][i]==1){
                vis[0][i]=1;
                dfshelper(0,i,vis,grid,n,m);
            }
            //last row
            if(grid[n-1][i]==1){
                vis[n-1][i]=1;
                dfshelper(n-1,i,vis,grid,n,m);
            }
        }
            for(int i=0;i<n;i++){
            //first col
                if(grid[i][0]==1){
                vis[i][0]=1;
                dfshelper(i,0,vis,grid,n,m);
            }
            //last col
            if(grid[i][m-1]==1){
                vis[i][m-1]=1;
                dfshelper(i,m-1,vis,grid,n,m);
            }
        }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1 && !vis[i][j]){
                count++;
            }
        }
    }
    return count;
}
    void dfshelper(int row,int col,vector<vector<int>>&vis,vector<vector<int>>& grid,int n,int m){
        for(int i=0;i<4;i++){
            int nrow=delrow[i]+row;
            int ncol=delcol[i]+col;

            if(nrow>=0 && nrow<n && 
            ncol>=0 && ncol<m &&
             grid[nrow][ncol]==1 && 
             !vis[nrow][ncol])
             {
                vis[nrow][ncol]=1;
                dfshelper(nrow,ncol,vis,grid,n,m);
            }
        }
    }
};