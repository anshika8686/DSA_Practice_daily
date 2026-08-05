class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        int minutes=0;
        int freshOrange=0;
       
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    freshOrange++;
                }
            }
        }

        if(freshOrange==0) return 0;// no fresh orange so nothing will rot
        if(q.empty()) return -1; // no rotten oranges

        int delrow[4]={0,-1,0,+1};
        int delcol[4]={-1,0,+1,0};

        while(!q.empty() && freshOrange>0){ //collection of rotten orange
        int size=q.size();
        for(int i=0;i<size;i++){
                int row=q.front().first;
                int col=q.front().second;
                q.pop();

            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];

                if(nrow>=0 && nrow<n 
                && ncol>=0 && ncol<m 
                && grid[nrow][ncol]==1) {
                grid[nrow][ncol]=2;
                q.push({nrow,ncol});
                freshOrange--;
                }
            }
        }
            minutes++;
    }
    if(freshOrange!=0) return -1;
    return minutes;
}
};
    