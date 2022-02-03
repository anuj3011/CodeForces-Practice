class Solution {
public:
     void dfs(vector<int>adj[], int n, int s, int d, bool &flag, bool vis[]){
        if(s==d){
            flag=true;
            return;
        }
        vis[s]=true;
        for(auto i:adj[s]){
            if(!vis[i]){
                dfs(adj,n,i,d,flag,vis);
            }
        }
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int s, int d) {
        bool vis[n];
	    vector<int>adj[n]; //edge list to adj list
	    for(auto i:edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
	    bool flag=false;
	    for(int i=0;i<n;i++) vis[i]=false;
	    dfs(adj,n,s,d,flag,vis);
	    return flag;
    }
};