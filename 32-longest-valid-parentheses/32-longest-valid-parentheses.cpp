class Solution {
public:
    int longestValidParentheses(string s) {
        int left=0,right=0,res=0;
        for(auto i:s){
            if(i=='(')
                left++;
            else
                right++;
            if(left==right) res=max(res,2*right);
            else if(right>left){
                left=0;
                right=0;
            }
        }
        left=0;
        right=0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='(')
                left++;
            else
                right++;
            if(left==right) res=max(res,2*right);
            else if(left>right){
                left=0;
                right=0;
            }
        }
        return res;
    }
};