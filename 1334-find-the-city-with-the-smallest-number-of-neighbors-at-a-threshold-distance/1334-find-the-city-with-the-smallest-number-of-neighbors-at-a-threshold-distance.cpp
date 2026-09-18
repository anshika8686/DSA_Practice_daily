class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dist(n,vector<int>(n,1e8));
        vector<int>count(n,0);
        int mini=INT_MAX;
        int maxCity=-1;
        //dist vector created
        for(int i=0;i<n;i++){
            dist[i][i]=0;
        }
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            if(w<=distanceThreshold)
            {dist[u][v]=w;
            dist[v][u]=w;
            } else{
            dist[u][v]=1e8;
            dist[v][u]=1e8;
            }
        }
        //floyd warshall algo to calculate shortest dist;
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][k]!=1e8
                     && dist[k][j]!=1e8
                     && dist[i][j]>dist[i][k]+dist[k][j] &&
                      dist[i][k]+dist[k][j]<=distanceThreshold){
                        dist[i][j]=dist[i][k]+dist[k][j];
                     }
                 }
             }
         }
         for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i!=j && dist[i][j]!=1e8 ){
                        count[i]++;
                    }
                }
         }

         for(int i=0;i<n;i++){
            if(mini>=count[i]){
                mini=count[i];
                maxCity=max(maxCity,i);
            }
         }
         return maxCity;
        
    }
};