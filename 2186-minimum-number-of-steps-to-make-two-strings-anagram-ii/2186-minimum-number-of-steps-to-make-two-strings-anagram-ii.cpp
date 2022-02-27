class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> mp;
        for(auto it:s)
            mp[it]++;
        int count=0;
        for(int i=0;i<t.length();i++){
            if(mp.find(t[i])!=mp.end()){
                if(mp[t[i]]>0)
                    mp[t[i]]--;
                else
                    count++;
            }else
                count++;
        }
        for(auto it: mp){
            count+=it.second;
        }
        return count;
    }
};