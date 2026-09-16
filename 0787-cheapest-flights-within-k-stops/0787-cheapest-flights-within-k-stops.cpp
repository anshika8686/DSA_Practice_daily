class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        queue<pair<int,pair<int,int>>>q; //flights,node,cost
        vector<int>dist(n,1e9);
        //adjlist
        for(auto flight:flights){
            int u=flight[0];
            int v=flight[1];
            int w=flight[2];
            adj[u].push_back({v,w});
        }
        q.push({0,{src,0}});
        while(!q.empty()){
            int flight=q.front().first;
            int node=q.front().second.first;
            int cost=q.front().second.second; //no of edges
            q.pop();

            if(flight<=k){
                for(auto neighbour:adj[node]){
                    int v=neighbour.first;
                    int wt=neighbour.second;
                    int newCost=cost+wt; //calc of price
                    if(newCost<dist[v]){ //pruning done here
                        dist[v]=newCost;
                        int newFlight=flight+1;
                        q.push({newFlight,{v,newCost}});
                    }
                }   
            }
        }
        if(dist[dst]==1e9) return -1;
        return dist[dst];     
    }
};