class Solution {
public:
    int numIslands(vector<vector<char>>& grid)
    {
        //islands->connected components
        int count=0;
        int n=grid.size();
        int m=grid[0].size();
    

        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(grid[row][col]=='1'){
                    count++;
                    dfs(row,col,grid,n,m);
                }
            }
        }
        return count;
        
    }
    // void bfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>& grid,int n,int m){
    //     vis[row][col]=1;
    //     queue<pair<int,int>>q;
    //     q.push({row,col});
    //     while(!q.empty()){
    //         int row=q.front().first;
    //         int col=q.front().second;
    //         q.pop();

    //         int delrow[4]={0,-1,0,+1};
    //         int delcol[4]={-1,0,+1,0};
    //         for(int k=0;k<4;k++){
    //             int nrow=row+delrow[k];
    //             int ncol=col+delcol[k];

    //             if(nrow>=0 && nrow<n && 
    //             ncol>=0 && ncol<m && 
    //             grid[nrow][ncol]=='1' &&
    //             !vis[nrow][ncol]){
    //                 q.push({nrow,ncol});
    //                 vis[nrow][ncol]=1;
    //             }
    //         }
    //     }

    // }

    void dfs(int row,int col,vector<vector<char>>& grid,int n,int m)
    {
        grid[row][col]='0';
        int delcol[4]={-1,0,+1,0};
        int delrow[4]={0,-1,0,+1};
        for(int k=0;k<4;k++){
                int nrow=row+delrow[k];
                int ncol=col+delcol[k];

             if(nrow>=0 && nrow<n && 
                ncol>=0 && ncol<m && 
                grid[nrow][ncol]=='1')
                {
                    dfs(nrow,ncol,grid,n,m);
                }
            }
        }
};