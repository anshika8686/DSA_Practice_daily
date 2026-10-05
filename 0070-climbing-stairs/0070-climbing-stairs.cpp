class Solution {
public:
    int climbStairs(int n) {
        int prev=1,prev1=1,curr=1;
        for(int i=2;i<=n;i++){
             curr=prev+prev1;
             prev=prev1;
             prev1=curr;
        }
        return curr;
    }
};