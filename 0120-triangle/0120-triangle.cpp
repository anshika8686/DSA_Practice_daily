class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int n=triangle.size();
        vector<int>next(n,0);
        for(int i=0;i<n;i++){
           next[i]=triangle[n-1][i];
        }
        for(int i=n-2;i>=0;i--){
            vector<int>curr(n,0);
          for(int j=0;j<=i;j++){
            curr[j]=triangle[i][j]+min(next[j],next[j+1]);
            }
            next=curr;
        }
        return next[0];
    }
    // int compute(int row,int col,int n,vector<vector<int>>& triangle,vector<vector<int>>&dp){
    //     if(row==n-1) return triangle[row][col];
    //     if(dp[row][col]!=-1) return dp[row][col];
    //     int left=compute(row+1,col,n,triangle,dp);
    //     int right=compute(row+1,col+1,n,triangle,dp);
    //     return dp[row][col]=triangle[row][col]+min(left,right);

    // }
};
