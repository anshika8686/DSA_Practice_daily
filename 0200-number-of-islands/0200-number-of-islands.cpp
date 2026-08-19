class Solution {
public:
int delrow[4]={0,-1,0,+1};
int delcol[4]={-1,0,+1,0};
    int numIslands(vector<vector<char>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    vis[i][j]=1;
                    dfs(i,j,vis,grid,m,n);
                    count++;
                }
            }
        }  
        return count;  
    }
    void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>& grid,int m,int n){
        for(int i=0;i<4;i++){
            int nrow=delrow[i]+row;
            int ncol=delcol[i]+col;

            if(nrow>=0 && nrow<m && 
            ncol>=0 && ncol<n && 
            grid[nrow][ncol]=='1' && 
            !vis[nrow][ncol])
            {
                vis[nrow][ncol]=1;
                dfs(nrow,ncol,vis,grid,m,n);
            }
        }
    }
};