class Solution {
public:

    void dfs(int node,vector<vector<int>>adjLs,vector<int>&vis){
        vis[node]=1;
        for(auto neighbour:adjLs[node]){
            if(!vis[neighbour]){
                dfs(neighbour,adjLs,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {

        int cnt=0;
        int V=isConnected.size();
        vector<vector<int>>adjLs(V);
        vector<int>vis(V,0);
        for(int u=0;u<V;u++){
            for(int v=0;v<V;v++){
                if(isConnected[u][v]==1 && u!=v){
                adjLs[u].push_back(v);
                adjLs[v].push_back(u);
            }
        }
    }
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,adjLs,vis);
                cnt++;
            }
        }
        return cnt;
        
    }
};