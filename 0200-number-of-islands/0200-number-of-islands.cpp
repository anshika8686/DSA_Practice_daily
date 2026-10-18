class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    bfs(i,j,m,n,grid,vis);
                    count++;
                }
            }
        }
        return count;
    }
        void bfs(int i,int j,int m ,int n,vector<vector<char>>& grid,vector<vector<int>>&vis){
            queue<pair<int,int>>q;
            q.push({i,j});
            vis[i][j]=1;
            int delrow[4]={-1,0,+1,0};
            int delcol[4]={0,-1,0,+1};
            while(!q.empty()){
                int row=q.front().first;
                int col=q.front().second;
                q.pop();

                for(int i=0;i<4;i++){
                    int nrow=delrow[i]+row;
                    int ncol=delcol[i]+col;

                    if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol]=='1' && !vis[nrow][ncol]){
                        q.push({nrow,ncol});
                        vis[nrow][ncol]=1;
                    }
                }
            }
        }
};