class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        set<pair<int,pair<int,int>>>st; //max effort
        st.insert({0,{0,0}}); //efforts,row,col
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=0;

        int delrow[4]={-1,0,+1,0};
        int delcol[4]={0,+1,0,-1};

        while(!st.empty()){
            int currEffort=st.begin()->first;
            int row=st.begin()->second.first;
            int col=st.begin()->second.second;
            st.erase({currEffort,{row,col}});

            if(row==n-1 && col==m-1){
                return currEffort;
            }

            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];

                if(nrow>=0 && nrow<n && 
                ncol>=0 && ncol<m){
                    int newEffort=max(currEffort, abs(heights[nrow][ncol]-heights[row][col]));
                    if(dist[nrow][ncol]>newEffort){
                        if(dist[nrow][ncol]!=1e9){
                            st.erase({dist[nrow][ncol],{nrow,ncol}});
                        }
                        dist[nrow][ncol]=newEffort;
                        st.insert({dist[nrow][ncol],{nrow,ncol}});
                    }

                }
            }
        }
        return -1;   
    }
};