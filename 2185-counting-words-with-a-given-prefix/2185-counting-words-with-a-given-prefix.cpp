class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int size=pref.length();
        int count=0;
        for(auto it: words){
            if(it.substr(0,size)==pref)
                count++;
            }
        return count;
    }
};