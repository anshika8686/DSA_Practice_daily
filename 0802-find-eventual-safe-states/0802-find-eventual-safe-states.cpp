class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<vector<int>>adjList(V);
        vector<int>indegree(V,0);
        queue<int>q;
        vector<int>safeNode;
        //Reverse adj List
          for(int i=0;i<V;i++){ //contains index
          for(auto node:graph[i]){
            adjList[node].push_back(i);
            indegree[i]++;
          }
        }
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
                
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            safeNode.push_back(node);

            for(auto neighbour:adjList[node]){
                indegree[neighbour]--;
                if(indegree[neighbour]==0){
                    q.push(neighbour);
                }
            }

        }
        sort(safeNode.begin(),safeNode.end());    
        return safeNode;
    }
};