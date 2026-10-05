class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1); //stores the precomputed result
        int count=compute(n,dp);
        return count;
        
    }
    int compute(int index,vector<int>&dp){
        if(index==0) return 1; 
        if(index==1) return 1;
        if(dp[index]!=-1) return dp[index];

        return dp[index]=compute(index-1,dp)+compute(index-2,dp);


    }
};