class Solution {
public:
    string reverseStr(string s, int k) {
        int i=0;
        // if(k>s.length()){
        //     reverse(s.begin(),s.end());
        //     return s;
        // }
        while(i<s.length() && i+k<=s.length()){
            reverse(s.begin()+i,s.begin()+i+k);
            i+=2*k;
        }
        reverse(s.begin()+i,s.end());
        return s;
    }
};