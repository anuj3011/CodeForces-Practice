class Solution {
public:
    bool isValid(int x, int y, int n,int m){
        if(x<0 || x>=n || y<0 || y>=m)
            return false;
        return true;
    }
    
    void dfs(vector<vector<char>>& grid, int n,int m, int x, int y,vector<vector<int>> &vis){
        vis[x][y]=1;
        int moveI[]={-1,0,0,1};
        int moveJ[]={0,1,-1,0};
        for(int K=0;K<4;K++){
            int i=moveI[K];
            int j=moveJ[K];
            if(isValid(i+x,y+j,n,m)){
                if(!vis[i+x][y+j]){
                    dfs(grid,n,m,i+x,j+y,vis);
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),0));
        int n=grid.size();
        int m= grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='0') vis[i][j]=1;
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]){
                    count++;
                    dfs(grid,n,m,i,j,vis);
                }
            }
        }
        return count;
    }
};