class Solution{
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
            rank[pv]++;
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        parent.resize(n+1);
        rank.assign(n+1,0);
         for(int i=0;i<n;i++){
            parent[i]=i;
        }
        unordered_map<string,int>mpp;
        vector<vector<string>>merged(n);
        vector<vector<string>>ans;
        
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){ //0th index respresents mail
               if(mpp.find(accounts[i][j])!=mpp.end()){ //already present in the map
                   int currIndex=i;
                   int prevIndex=mpp[accounts[i][j]];
                   UnionByRank(currIndex,prevIndex);
               }
               else{
                mpp[accounts[i][j]]=i;
               }
            }
        }
            for(auto it : mpp) {
              string email = it.first;
              int account = it.second;
              int p=findPar(account,parent);
              merged[p].push_back(email);
            }
            for( auto& email:merged)
            sort(email.begin(),email.end());
//             key=account , value=mail

              for(int i = 0; i < n; i++) {
    if(merged[i].empty())
        continue;

    vector<string> temp;
    temp.push_back(accounts[i][0]);

    for(auto email : merged[i]) {
        temp.push_back(email);
    }

    ans.push_back(temp);
}
         return ans;
    }
};