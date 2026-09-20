class Solution {
public:
    int findPar(int u,vector<int>&parent){
        if(u==parent[u]) return u;
        return parent[u]=findPar(parent[u],parent);
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V=isConnected.size();
        vector<int>parent(V+1);
        vector<int>rank(V+1,0);
        unordered_set<int>st;
        for(int i=0;i<V;i++){
            parent[i]=i;
        }
        int count=1;
        for(int i=0;i<V;i++){
            for(int j=i+1;j<V;j++){
                if(isConnected[i][j]==1 && i!=j){
                    int pu=findPar(i,parent);
                    int pv=findPar(j,parent);

                    if(pu == pv) continue;

                    if(rank[pu]<rank[pv]) parent[pu]=pv;
                    else if(rank[pu]>rank[pv]) parent[pv]=pu;
                    else {
                        parent[pu]=pv;
                        rank[pv]++;
                    }
                }
            }
        }
        for(int i=0;i<V;i++){
            st.insert(findPar(i,parent));
        }
        return st.size();

        
    }
};