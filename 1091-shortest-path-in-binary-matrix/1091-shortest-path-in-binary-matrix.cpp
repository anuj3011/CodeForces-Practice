class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1)
            return -1;
        queue<vector<int>> q;
        // int dist=1;
        q.push({0,0,1});    //(0,0) is coordinate and 1 is distance
        grid[0][0]=1;
        int dir [8][2] ={{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1},{1,-1}, {-1,1}, {-1,-1}};
        while(!q.empty()){
            int s=q.size();
            while(s--){
                vector<int> temp=q.front();
                q.pop();
                if(temp[0]==n-1 && temp[1]==n-1){
                    return temp[2];
                }
                for(auto d: dir){
                    int r= temp[0] + d[0];
                    int c= temp[1] + d[1];
                    if(r>=0 && c>=0 && r<n && c<n && grid[r][c]==0){
                        q.push({r,c,temp[2]+1});
                        grid[r][c]=1;
                    }
                }
            }
        }
        return -1;
    }
};