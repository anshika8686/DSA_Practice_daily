class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        // vector<vector<int>>vis(n,vector<int>(m,0));
        int orgColor=image[sr][sc];
        if(orgColor==color) return image;
        dfs(image,sr,sc,color,orgColor,n,m);
        return image; 
    }
    void dfs(vector<vector<int>>& image, int sr, int sc, int color,int orgColor,int n,int m){
        image[sr][sc]=color;
        int delrow[4]={0,-1,0,+1};
        int delcol[4]={-1,0,+1,0};
        for(int i=0;i<4;i++){
            int nrow=delrow[i]+sr;
            int ncol=delcol[i]+sc;

            if(nrow>=0 && nrow<n &&
            ncol>=0 && ncol<m &&
            (image[nrow][ncol]==orgColor)){
                dfs(image,nrow,ncol,color,orgColor,n,m);
            }
            
        }

    }
};