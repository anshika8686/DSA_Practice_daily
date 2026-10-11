class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        int money=compute(n-1,nums,dp);
        return money;
    }
    int compute(int i,vector<int>& nums,vector<int>& dp){
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        int take=nums[i]+compute(i-2,nums,dp);
        int nottake=0+compute(i-1,nums,dp);
        return dp[i]=max(take,nottake);
    }
};