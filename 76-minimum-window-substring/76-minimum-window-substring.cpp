class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> map;
        for(int i=0;i<t.length();i++){
            map[t[i]]++;
        }
        int count=map.size();
        int i=0,j=0;
        int k=INT_MAX;
        int ans_i=-1,ans_j=-1;
        while(j<s.length()){
            if(map.find(s[j])!=map.end()){
                map[s[j]]--;
                if(map[s[j]]==0){
                    count--;
                }
            }
            if(count>0){
                j++;
            }
            else if(count==0){
                while(count==0){
                    if(map.find(s[i])!=map.end()){
                        map[s[i]]++;
                        if(map[s[i]]>0) count++;
                    }
                    i++;
                }
                // cout<<i<<" "<<j<<endl;
                if(j-i<k){
                    ans_i=i-1;
                    ans_j=j;
                    k=j-i;
                    // cout<<ans_i<<" "<<ans_j;
                }
                j++;
            }
        }
        string ans="";
        if(k==INT_MAX)
            return ans;
        else
        {
            for(int i=ans_i;i<=ans_j;i++){
                ans.push_back(s[i]);
            }
            return ans;
        }
    }
};