class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int count=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='(')
                count++;
            else if(s[i]==')'){
                if(count==0)
                    s[i]='#';
                else{
                    count--;
                }
            }
        }
        count=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]==')')
                count++;
            else if(s[i]=='('){
                if(count==0)
                    s[i]='#';
                else
                    count--;
            }
        }
        string ans="";
        for(auto it: s){
            if(it != '#')
                ans+=it;
        }
        return ans;
    }
};