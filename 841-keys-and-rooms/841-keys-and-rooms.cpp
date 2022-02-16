class Solution {
public:
    void dfs(int start, vector<vector<int>> rooms, bool vis[]){
        vis[start]=true;
        for(int i:rooms[start]){
            if(!vis[i]){
                dfs(i,rooms,vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        bool vis[rooms.size()];
        for(int i=0;i<rooms.size();i++){
            vis[i]=false;
        }
        dfs(0,rooms,vis);
        for(bool i: vis){
            if(i==false)
                return false;
        }
        return true;
    }
};