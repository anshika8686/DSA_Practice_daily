class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n+1,0);
        vector<int>color(n+1,-1);
    
        for(int i=0;i<n;i++){
            if(!vis[i]){
                color[i]=0;
                if(bfs(i,vis,color,graph)==false)
                return false;
            }
        }
         return true;
    }
    bool bfs(int i, vector<int>&vis, vector<int>&color, vector<vector<int>>&graph)
        {
        queue<int>q;
        q.push(i);
        vis[i]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(auto it:graph[node]){
                if(!vis[it] && color[it]==-1){
                    color[it]=!color[node];
                    vis[it]=1;
                    q.push(it);
                } 
                else if(color[node]==color[it]){
                    return false;
                }
            }
        }
        return true;
    }
};