class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int>vis(V,0);
        vector<int>pathVis(V,0);
        vector<int>safe(V,0);
        vector<int>ans;
        bool flag;

        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,vis,pathVis,safe,graph)==true)
                flag=true;
            }
        }  
        for(int i=0;i<V;i++){
            if(safe[i]==1){
                ans.push_back(i);
            }
        } 
        return ans;
    }
    bool dfs(int node,vector<int>&vis,vector<int>&pathVis,vector<int>&safe,vector<vector<int>>& graph){
        vis[node]=1;
        pathVis[node]=1;

        for(auto neighbour:graph[node]){
            if(!vis[neighbour]){
                if(dfs(neighbour,vis,pathVis,safe,graph)==false)
                {safe[node]=0;
                return false; 
                } 
            }
            else if(vis[neighbour] && pathVis[neighbour]){
                safe[node]=0;
                return false; //not safe  
            }
        }
        pathVis[node]=0;
        safe[node]=1;
        return true;
    }
};