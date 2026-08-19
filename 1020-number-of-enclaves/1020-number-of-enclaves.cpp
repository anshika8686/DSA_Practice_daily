class Solution {
public:
int delrow[4]={0,-1,0,+1};
int delcol[4]={-1,0,+1,0};
    int numEnclaves(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;

        
        for(int i=0;i<m;i++){
            //first row
            if(grid[0][i]==1){
                grid[0][i]=0;
                dfshelper(0,i,grid,n,m);
            }
            //last row
            if(grid[n-1][i]==1){
                grid[n-1][i]=0;
                dfshelper(n-1,i,grid,n,m);
            }
        }
            for(int i=0;i<n;i++){
            //first col
                if(grid[i][0]==1){
                grid[i][0]=0;
                dfshelper(i,0,grid,n,m);
            }
            //last col
            if(grid[i][m-1]==1){
                grid[i][m-1]=0;
                dfshelper(i,m-1,grid,n,m);
            }
        }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                count++;
            }
        }
    }
    return count;
}
    void dfshelper(int row,int col,vector<vector<int>>& grid,int n,int m){
        for(int i=0;i<4;i++){
            int nrow=delrow[i]+row;
            int ncol=delcol[i]+col;

            if(nrow>=0 && nrow<n && 
            ncol>=0 && ncol<m &&
             grid[nrow][ncol]==1)
             {
                grid[nrow][ncol]=0;
                dfshelper(nrow,ncol,grid,n,m);
            }
        }
    }
};