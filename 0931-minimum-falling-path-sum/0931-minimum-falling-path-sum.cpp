// class Solution {
// public:
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n=matrix.size();
//         int m=matrix[0].size();
//         vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
//         int mini=INT_MAX;
//        
//            for(int j=0;j<m;j++){
//             int val=compute(n-1,j,m,matrix,dp);
//             mini=min(mini,val);
//         }
//         return mini;
//     }
//     int compute(int i,int j,int m,vector<vector<int>>& matrix,vector<vector<int>>&dp){
        
//         if(j<0 || j>=m ) return INT_MAX/2;

//         if(i==0) return matrix[0][j];

//         if(dp[i][j]!=-1) return dp[i][j];

//         int left=matrix[i][j]+compute(i-1,j-1,m,matrix,dp);
//         int up=matrix[i][j]+compute(i-1,j,m,matrix,dp);
//         int right=matrix[i][j]+compute(i-1,j+1,m,matrix,dp);
//         return dp[i][j]=min({left,up,right});
//     }   
// };

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>prev(m,0);
        for(int j=0;j<m;j++){
        prev[j]=matrix[0][j];
        }

        int mini=INT_MAX;

        for(int i=1;i<n;i++){
            vector<int>curr(m,0);
           for(int j=0;j<m;j++){
            int left=INT_MAX,right=INT_MAX,up=INT_MAX;

         if(i>0 && j>0) left=matrix[i][j]+prev[j-1];
         if(i>0) up=matrix[i][j]+prev[j];
         if(i>0 && j<m-1) right=matrix[i][j]+prev[j+1];
         curr[j]=min({left,up,right});
        }
        prev=curr;
    } 
    
    for(int j=0;j<m;j++){
        mini=min(mini,prev[j]);
    }
    return mini;
    }
};
