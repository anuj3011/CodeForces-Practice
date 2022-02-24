class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int count=0;
        int maxC=0;
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]){
                    count=1;
                    dfs(grid,n,m,i,j,vis,count,maxC);
                }
            }
        }
        return maxC;
    }
    
    void dfs(vector<vector<int>> &grid, int n, int m, int sr,int sc,vector<vector<bool>>                   &vis,int &count,int &maxC){
        vis[sr][sc]=true;
        maxC=max(count,maxC);
        for(int i=-1;i<2;i++){
            if(validI(sr+i,n)){
                if(!vis[sr+i][sc] && grid[sr+i][sc]){
                    count++;
                    dfs(grid,n,m,sr+i,sc,vis,count,maxC);
                }
            }
        }
        for(int i=-1;i<2;i++){
            if(validJ(sc+i,m)){
                if(!vis[sr][sc+i] && grid[sr][sc+i]){
                    count++;
                    dfs(grid,n,m,sr,sc+i,vis,count,maxC);
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