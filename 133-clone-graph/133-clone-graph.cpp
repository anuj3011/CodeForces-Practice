/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* node,unordered_map<Node*,Node*> &mp,set<Node*> &vis){
        vis.insert(node);
        Node* copy=new Node(node->val);
        mp[node]=copy;
        for(auto v: node->neighbors){
            if(vis.find(v)==vis.end()){
                dfs(v,mp,vis);
            }
        }
    }
    
    void makeEdges(unordered_map<Node*,Node*> mp){
        for(auto u: mp){
            for(auto v: u.first->neighbors){
                u.second->neighbors.push_back(mp[v]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        unordered_map<Node*,Node*> mp;
        set<Node*> vis;
        Node* copy_node = new Node(node->val);
        vis.insert(copy_node);
        mp.insert({node,copy_node});
        for(auto start : node->neighbors){
             if(vis.find(start) == vis.end()){
                dfs(start,mp,vis);
             }
        }
        makeEdges(mp);
        return mp[node];
    }
};