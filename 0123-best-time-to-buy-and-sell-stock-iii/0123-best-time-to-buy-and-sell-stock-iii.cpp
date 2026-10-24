class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(5,0)));
        
        for(int index=n-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                for(int k=1;k<=4;k++){
                    if(buy==1)
                    dp[index][1][k]=
                    max({-prices[index]+dp[index+1][0][k-1]
                    ,dp[index+1][1][k]});
                    else
                    dp[index][0][k]=
                    max({prices[index]+dp[index+1][1][k-1]
                    ,dp[index+1][0][k]});
                }
            }
        }
            return dp[0][1][4];
    }
};