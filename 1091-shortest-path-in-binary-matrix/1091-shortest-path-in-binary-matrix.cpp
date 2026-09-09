class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    
    int n=grid.size();
    if(grid[0][0]!=0 || grid[n-1][n-1] !=0) return -1 ; //edge case
   
    int count=1;
    queue<pair<int,int>>q;
    vector<vector<int>>vis(n,vector<int>(n,0));
    q.push({0,0});
    vis[0][0]=1;

    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size ;i++){
            int row=q.front().first;
        int col=q.front().second;
        q.pop();
       

        if(row==n-1 && col==n-1){
            return count;
        }

        int dist[3]={-1,0,+1};
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                int nrow=row+dist[i];
                int ncol=col+dist[j];

                if(nrow>=0 && nrow<n 
                && ncol>=0 && ncol<n 
                && !vis[nrow][ncol]&&
                grid[nrow][ncol]==0){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }
            }
        }
    }
         count++;
    }
    return -1;  
    }
};