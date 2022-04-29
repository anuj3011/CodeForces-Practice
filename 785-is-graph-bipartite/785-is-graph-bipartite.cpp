class Solution {
public:
    bool dfs(vector<int> adj[], int col[],int start, int cr){
        col[start]=cr;
        bool flag=true;
        for(auto it: adj[start]){
            if(col[it]==-1){
                flag=dfs(adj,col,it,1-cr);
                if(!flag)
                    return false;
            }else{
                if(col[it]==col[start])
                    return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
       
        int V=graph.size();
        vector<int> adj[V];
        
        //Create adjacency list from given graph.
        for(int i=0; i<V; i++){
            vector<int> t = graph[i];
            for(auto& num:t) adj[i].push_back(num);
        }
        int col[V];
	    for(int i=0;i<V;i++){
	        col[i]=-1;
	    }
	    bool flag=true;
	    for(int i=0;i<V;i++){
	        if(col[i]==-1){
	            flag=dfs(adj,col,i,1);
	            if(!flag)
	                return false;
	        }
	    }
	    return true;
    }
};