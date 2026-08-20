class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int>vis(V,0);
        vector<int>color(V,-1);
        for(int i=0;i<V;i++){
            if(!vis[i])
            {
                color[i]=0;
                if(dfs(i,graph,vis,color)==false)
                return false;
            }
        }
        return true;
    }
    bool dfs(int node,vector<vector<int>>& graph,vector<int>&vis,vector<int>&color){
        vis[node]=1;
        int c=color[node]==0?1:0;
        for(auto it:graph[node]){
            if(!vis[it] && color[it]==-1)
            {
                color[it]=c;
                if(!dfs(it,graph,vis,color)) return false;
            }
            else if(color[node]==color[it]){ //it is vis and same colour as neighbouring one
                return false;
            }
        }
        return true;
    }
};