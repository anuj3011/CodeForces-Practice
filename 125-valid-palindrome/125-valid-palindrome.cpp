class Solution {
public:
    bool isPalindrome(string s) {
        string temp="";
        for(auto it: s){
            // int t=(int) it;
            if(isalnum(it)){
                temp+=tolower(it);
            }
        }
        int i=0,j=temp.length()-1;
        while(i<=j){
            if(temp[i]!=temp[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};