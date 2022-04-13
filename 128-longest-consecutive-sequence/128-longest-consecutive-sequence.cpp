class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int it: nums) s.insert(it);
        
        int ans=0;
        for(auto it: nums){
            if(s.find(it-1)==s.end()){
                int currNum=it;
                int len=1;
                while(s.find(currNum+1)!=s.end()){
                    currNum+=1;
                    len++;
                }
                ans=max(len,ans);
            }
        }
        return ans;
    }
};