class Solution {
public:
    static const int n=100001;
    vector<int> adj[n];
    
    void dfs(string& s, int vertex, vector<char> &ch, vector<int> &indicies, vector<bool>             &vis){
        ch.push_back(s[vertex]);
        indicies.push_back(vertex);
        vis[vertex]=true;
        for(int it: adj[vertex]){
            if(!vis[it]){
                dfs(s,it,ch,indicies,vis);
            }
        }
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        // n=s.length();
        
        for(auto it: pairs){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<bool> vis(n,false);
        for(int i=0;i<s.size();i++){
            if(!vis[i]){
                vector<char> ch;
                vector<int> indicies;
                dfs(s,i,ch,indicies,vis);
                sort(ch.begin(),ch.end());
                sort(indicies.begin(),indicies.end());
                int nn=ch.size();
                for(int ind=0;ind<nn;ind++){
                    s[indicies[ind]]=ch[ind];
                }
            }
        }
        return s;
    }
};