class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        int dest=stones[n-1];
        unordered_map<int,int>pos;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        for(int i=0;i<stones.size();i++){
            pos[stones[i]]=i;
        }
        return compute(0,0,pos,dp,stones);
    }
    bool compute(int i, int j,
             unordered_map<int,int>& pos,
             vector<vector<int>>& dp,
             vector<int>& stones) {

    if(i == stones.size() - 1)
        return true;

    if(dp[i][j] != -1)
        return dp[i][j] == 1;

    for(int nextJump = j - 1; nextJump <= j + 1; nextJump++) {

        if(nextJump <= 0)
            continue;

        int nextPos = stones[i] + nextJump;

        if(pos.find(nextPos) != pos.end()) {

            int nextIndex = pos[nextPos];

            if(compute(nextIndex, nextJump, pos, dp, stones)) {
                dp[i][j] = 1;
                return true;
            }
        }
    }

    dp[i][j] = 0;
    return false;
}
};