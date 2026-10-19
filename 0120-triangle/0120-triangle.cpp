class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            dp[n-1][i]=triangle[n-1][i];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                dp[i][j]=triangle[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
    // int compute(int row,int col,int n,vector<vector<int>>& triangle,vector<vector<int>>&dp){
    //     if(row==n-1) return triangle[row][col];
    //     if(dp[row][col]!=-1) return dp[row][col];
    //     int left=compute(row+1,col,n,triangle,dp);
    //     int right=compute(row+1,col+1,n,triangle,dp);
    //     return dp[row][col]=triangle[row][col]+min(left,right);

    // }
};
