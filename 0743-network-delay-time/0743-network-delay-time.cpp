class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //adjList
        vector<vector<pair<int,int>>>adjList(n+1);
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq; //time,node
        vector<int>dist(n+1,1e9);
        int max_Dist=0;
        for(auto time:times){
            int u=time[0];
            int v=time[1];
            int w=time[2];
            adjList[u].push_back({v,w});
        }
        pq.push({0,k});
        dist[k]=0;
        while(!pq.empty()){
            int time=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            for(auto neighbour:adjList[node]){
                int v=neighbour.first;
                int w=neighbour.second;
                if(dist[v]>dist[node]+w){
                    dist[v]=dist[node]+w;
                    pq.push({dist[v],v});
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(dist[i]==1e9) return -1;
            else max_Dist=max(max_Dist,dist[i]);
        }

        return max_Dist;   
    }
};