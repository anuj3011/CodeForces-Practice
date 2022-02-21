class Solution {
public:
    string reverseWords(string s) {
        int i=0,j=0;
        while(j<s.length()){
            if(s[j]!=' ')
                j++;
            else{
                reverse(s.begin()+i,s.begin()+j);
                i=j+1;
                j++;
            }
        }
        reverse(s.begin()+i,s.end());
        return s;
    }
};