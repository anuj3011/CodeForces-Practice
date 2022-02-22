class Solution {
public:
   bool isValid(string s) {
        stack<char> st;
        for(char it: s){
            if(it=='('||it=='{'||it=='[')
                st.push(it);
            else{
                if(st.empty()) return false;        //closing bracket before opening
                
                if((st.top()=='{' && it=='}') || 
                   (st.top()=='(' && it==')') || 
                   (st.top()=='[' && it==']'))
                    st.pop();
                else
                    return false;//not in correct order
                
            }
        }
        if(st.empty()) return true;
        else return false;
    }
};