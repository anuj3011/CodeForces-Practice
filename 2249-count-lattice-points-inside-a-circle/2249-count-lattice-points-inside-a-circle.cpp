class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        int n=circles.size();
        set<pair<int,int>> s;
        for(int i=0;i<n;i++){
            int x=circles[i][0],y=circles[i][1],r=circles[i][2];
            for(int i=-r;i<=r;i++){
                for(int j=-r;j<=r;j++){
                    if((i*i + j*j)<=r*r){
                        s.insert({x+i,y+j});
                    }
                }
            }
        }
        return s.size();
    }
};