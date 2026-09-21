class Solution {
public:
    int findPar(int u,vector<int>&parent){
        if(u==parent[u]) return u;
        return parent[u]=findPar(parent[u],parent);
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        vector<int>rank(n+1,0);
        vector<int>parent(n+1);
        int components=n;
        int count=0;
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(const auto&connection:connections){
            int u=connection[0];
            int v=connection[1];

            int pu=findPar(u,parent);
            int pv=findPar(v,parent);

            if(pu==pv) {
                count++;
                continue;
            }
            if(rank[pu]<rank[pv])  parent[pu]=pv;
            else if(rank[pu]>rank[pv]) parent[pv]=pu;
            else{
                parent[pu]=pv;
                rank[pv]++;
            }
            components--;
        }
       if(count>=components-1) return components-1;
       return -1;
    }
};