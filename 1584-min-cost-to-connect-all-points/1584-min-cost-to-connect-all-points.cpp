class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        bool vis[n];
        memset(vis,false,sizeof(vis));
        // dis[0]=0;
        // set<pair<int,int>> s;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        // s.insert({0,0});
        heap.push({0,0});
        int minCost=0;
        int remaining=0;
        while(remaining<n){
            // auto itr=*(s.begin());
            // s.erase(itr);
            pair<int, int> topElement = heap.top();
            heap.pop();
            int currNode=topElement.second;
            if(vis[currNode])
                continue;
            vis[currNode]=true;
            int wt=topElement.first;
            minCost+=wt;
            remaining++;
            for(int nextNode=0;nextNode<n;nextNode++){
                if(!vis[nextNode]){
                    int currWt= abs(points[currNode][0]-points[nextNode][0])+
                                abs(points[currNode][1]-points[nextNode][1]);
                    // s.insert({currWt,nextNode});
                    heap.push({currWt,nextNode});
                }
            }
        }
        return minCost;
    }
};