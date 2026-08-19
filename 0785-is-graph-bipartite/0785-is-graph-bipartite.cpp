class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int>vis(V,0);
        vector<int>color(V,-1);
        for(int i=0;i<V;i++){
            if(!vis[i])
            {
            queue<int>q;
            q.push(i);
            color[i]=0;
             vis[i]=1;

           while(!q.empty()){
            int node=q.front();
            q.pop();
        
        for(auto it:graph[node]){
                int c=color[node]==0?1:0;
                if(color[it]==-1 && !vis[it]){
                    color[it]=c;
                    vis[it]=1;
                    q.push(it);
                }
                else if(vis[it] && color[it]==color[node])
                return false;
            }
        }
    }
}  
    return true;
    }
};