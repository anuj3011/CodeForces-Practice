// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool isSafe(int node,int c,bool graph[101][101],int V,int col[]){
    for(int k=0;k<V;k++){
        if(k!=node && graph[node][k]==1 && col[k]==c)
            return false;
    }
    return true;
}

bool solve(int node, int col[], bool graph[101][101], int m, int V)
{
    if(node==V)
        return true;
    for(int i=1;i<=m;i++){
        if(isSafe(node,i,graph,V,col)){
            col[node]=i;
            if(solve(node+1,col,graph,m,V))
                return true;
            col[node]=0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int V)
{
    // your code here
    int col[V]={0};
    if(solve(0,col,graph,m,V)) return true;

    return false;
    
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends