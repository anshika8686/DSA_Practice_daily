class Solution {
public:

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses,0);
        vector<int>vis(numCourses,0);
        vector<vector<int>>adj(numCourses);
        queue<int>q;
        vector<int>ans;
        //CREATED ADJ LIST
        for(auto it:prerequisites){
            int u=it[0];
            int v=it[1];
            adj[v].push_back(u);
        }
        //CREATED INDEGREE LIST
        for(int i=0;i<numCourses;i++){
          for(auto neighbour:adj[i]){
            indegree[neighbour]++;
          }
        }
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    ans.push_back(node);

                    for(auto neighbour: adj[node]){
                        indegree[neighbour]--;
                        if(indegree[neighbour]==0){
                            q.push(neighbour);
                    }
                }
            }    
        return ans.size()==numCourses? ans:vector<int>();
    }
    // void dfs(int node,vector<int>&vis, vector<int>& indegree,vector<vector<int>>&adj){
    //     vis[node]=1;
    //     if(indegree[node]==0){
    //         ans.push_back(node);
    //     }
    //     for(auto neighbour: adj[node]){
    //         indegree[neighbour]--;
    //         dfs(neighbour,vis,indegree,adj);
    //     }
    // }
};