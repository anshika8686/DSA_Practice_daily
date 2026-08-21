class Solution {
public:

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int V=graph.size();
        vector<int>pathVis(V,0);
        vector<int>vis(V,0);
        vector<int>check(V,0);
        bool flag=true;
        vector<int>safeNode;
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,vis,pathVis,graph,check)==false)
                flag=false;
            }
        }
        for(int i=0;i<V;i++){
            if(check[i]==1){
                safeNode.push_back(i);
            }
        }
        return safeNode;
    }
    bool dfs(int node,vector<int>&vis,vector<int>&pathVis,vector<vector<int>>& graph,vector<int>&check){
        vis[node]=1;
        pathVis[node]=1;
        for(auto neighbour:graph[node]){
                if(!vis[neighbour]){ //not a part of cycle
                if(dfs(neighbour,vis,pathVis,graph,check)==true)
                return true;
            }
            else if(pathVis[neighbour]==1){ //part of cycle
                return true;
            }
        }
        check[node]=1;//safenodes
        pathVis[node]=0;
        return false;
    }
};