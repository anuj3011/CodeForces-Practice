class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        dfs(image,n,m,sr,sc,newColor,vis);
        image[sr][sc]=newColor;
        return image;
    }
    
    void dfs(vector<vector<int>> &image, int n, int m, int sr,int sc,int                                     newColor,vector<vector<bool>> &vis){
        vis[sr][sc]=true;
        for(int i=-1;i<2;i++){
            if(validI(sr+i,n)){
                if(!vis[sr+i][sc]){
                    if(image[sr+i][sc]==image[sr][sc]){
                        dfs(image,n,m,sr+i,sc,newColor,vis);
                        image[sr+i][sc]=newColor;
                    }
                }
            }
        }
        for(int i=-1;i<2;i++){
            if(validJ(sc+i,m)){
                if(!vis[sr][sc+i]){
                    if(image[sr][sc+i]==image[sr][sc]){
                        dfs(image,n,m,sr,sc+i,newColor,vis);
                        image[sr][sc+i]=newColor;
                    }
                }
            }
        }
    }
    bool validI(int x,int n){
        if(x<n && x>=0)
            return true;
        return false;
    }
    bool validJ(int y, int m){
        if(y<m && y>=0){
            return true;
        }
        return false;
    }
};