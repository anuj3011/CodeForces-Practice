class Solution {
public:
    int lengthOfLastWord(string s) {
        int len=0;
        int n=s.length()-1;
        while(n>=0 && s[n]==' ')
            n--;
        while(n>=0 && s[n]!=' '){
            len++;
            n--;
        }
        return len;
    }
};