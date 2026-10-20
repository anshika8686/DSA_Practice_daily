class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(m,-1)));
        int c1=0,c2=m-1;
        int maxi=compute(0,c1,c2,grid,n,m,dp);
        return maxi;  
    }
    int compute(int row,int c1,int c2,vector<vector<int>>& grid,int n,int m,vector<vector<vector<int>>>&dp){
        if(c1<0 || c1>=m || c2<0 || c2>=m) return INT_MIN/2; //int min because we need to find maximum
        if(row==n-1) {
            if(c1==c2) return grid[row][c1];
            if(c1!=c2) return grid[row][c1]+grid[row][c2];
        }//reached dest 

        if(dp[row][c1][c2]!=-1) return dp[row][c1][c2];

        int maxi=INT_MIN;
        int cherry= grid[row][c1];
         if(c1!=c2) cherry+=grid[row][c2];
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                int val=cherry+compute(row+1,c1+i,c2+j,grid,n,m,dp);
                maxi=max(maxi,val);
                dp[row][c1][c2]=maxi;
            }

        }
        return maxi;
    }
};