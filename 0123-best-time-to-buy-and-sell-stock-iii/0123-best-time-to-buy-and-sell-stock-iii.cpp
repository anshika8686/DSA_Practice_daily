class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>prev(2,vector<int>(5,0));
        
        for(int index=n-1;index>=0;index--){
            vector<vector<int>>curr(2,vector<int>(5,0));
                for(int k=1;k<=4;k++){
                curr[1][k]=max({-prices[index]+prev[0][k-1],prev[1][k]});
                curr[0][k]=max({prices[index]+prev[1][k-1],prev[0][k]});
                }
            prev=curr;
        }
            return prev[1][4];
    }
};