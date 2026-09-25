class Solution {
public:
vector<int>parent;
vector<int>rank;
    int findPar(int u,vector<int>&parent){
        if(u==parent[u]) return u;
        return parent[u]=findPar(parent[u],parent);
    }
    void UnionByRank(int u,int v){
        int pu=findPar(u,parent);
        int pv=findPar(v,parent);
        if(pu==pv) return;

        if(rank[pu]<rank[pv]) parent[pu]=pv;
        else if(rank[pv]<rank[pu]) parent[pv]=pu;
        else{
            parent[pu]=pv;
            rank[pu]++;
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        unordered_set<int>used;
        unordered_set<int>components;
        int maxrow=0,maxcol=0;
        for(const auto &it:stones){ //o(n)
             maxrow=max(maxrow,it[0]);
             maxcol=max(maxcol,it[1]);
        }
        parent.resize(maxrow+maxcol+2);
        rank.assign(maxrow+maxcol+2,0);//o(maxrow+maxcol+2)
        for(int i=0;i<maxrow+maxcol+2;i++){
            parent[i]=i;
        }
        //formation of component
        for(const auto &it:stones){ //O(stones.size())
            int row=it[0];
            int col=it[1]+maxrow+1;
            UnionByRank(row,col);
            used.insert(row);
            used.insert(col);
        }
        //total stones-no of components
        for(auto it:used){//o(2*stones.size())
            components.insert(findPar(it,parent));
        }
        return stones.size()-components.size();
    }
};