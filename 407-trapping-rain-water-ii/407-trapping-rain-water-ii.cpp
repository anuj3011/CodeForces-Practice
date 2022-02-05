class Solution {
public:
    vector<vector<bool>> vis;
    int n,m,water;
    
    bool validI(int x){
        if(x<n && x>=0 )
            return true;
        return false;
    }
    bool validJ(int x){
        if(x<m && x>=0 )
            return true;
        return false;
    }
    
    void checkNeighbours(set<pair<int,pair<int,int>>> &s, pair<int,int>                                     index,vector<vector<int>>& heightMap){
        
        int x= index.first;
        int y=index.second;
        for(int i=-1;i<2;i++){
            if(validI(x+i)){
                if(!vis[x+i][y]){
                    vis[x+i][y]=true;
                    if(heightMap[x+i][y]<heightMap[x][y]){
                        water+=(heightMap[x][y]-heightMap[x+i][y]);
                        heightMap[x+i][y]=heightMap[x][y];
                        s.insert({heightMap[x+i][y],{x+i,y}});
                    }else{
                        s.insert({heightMap[x+i][y],{x+i,y}});
                    }  
                }
            }
        }
        
        for(int j=-1;j<2;j++){
            if(validJ(y+j)){
                if(!vis[x][y+j]){
                    vis[x][y+j]=true;
                    if(heightMap[x][y+j]<heightMap[x][y]){
                        water+=(heightMap[x][y]-heightMap[x][y+j]);
                        heightMap[x][y+j]=heightMap[x][y];
                        s.insert({heightMap[x][y+j],{x,y+j}});
                    }else{
                        s.insert({heightMap[x][y+j],{x,y+j}});
                    }
                }
            }
        }
        
    }
    
    int trapRainWater(vector<vector<int>>& heightMap) {
        water=0;
        n=heightMap.size();
        m=heightMap[0].size();
        // priority_queue<pair<int,pair<int,int>>> pq;
        set<pair<int,pair<int,int>>> s;
        
        for(int i=0;i<n;i++){
	       vis.push_back(vector<bool>(n,false));
	    }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    s.insert({heightMap[i][j],{i,j}});
                    vis[i][j]=true;
                }
            }
        }
        while(!s.empty()){
            // pair<int,pair<int,int>> temp= pq.top();
            auto it= *(s.begin());
            s.erase(it);
            // pq.pop();
            
            pair<int,int> index= it.second;
            checkNeighbours(s,index,heightMap);
        }
        return water;
    }
};