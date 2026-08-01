class Solution {
public:

    void dfs(int node,vector<vector<int>>& isConnected,vector<int>&vis){
        vis[node]=1;
        for(int u=0;u<isConnected.size();u++){
            if(!vis[u] && isConnected[node][u] == 1 ){
                dfs(u,isConnected,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cnt=0;
        int V=isConnected.size();  
        vector<int>vis(V,0);

        for(int u=0;u<V;u++){
            if(!vis[u]){
                cnt++;
                dfs(u,isConnected,vis);
                    }
                }    
        return cnt;
        
    }
};