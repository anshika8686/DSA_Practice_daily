class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int total=0;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                 total=total+compute(i,j,matrix,dp);
            }
        }
        return total;
    }
    int compute(int row,int col,vector<vector<int>>& matrix,vector<vector<int>>&dp){
        if(col<0) return 0;
        if(row==0) return matrix[row][col];
        if(matrix[row][col]==0) return 0;
        if(dp[row][col]!=-1) return dp[row][col];
        int up=compute(row-1,col,matrix,dp);
        int diagonal=compute(row-1,col-1,matrix,dp);
        int right=compute(row,col-1,matrix,dp);
        return dp[row][col]=1+min({up,diagonal,right});
    }
};