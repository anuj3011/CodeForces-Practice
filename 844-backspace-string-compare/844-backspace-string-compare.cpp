class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st;
        for(auto it: s){
            if(it=='#' && !st.empty())
                st.pop();
            else if(it=='#' && st.empty())
                continue;
            else
                st.push(it);
        }
        s="";
        while(!st.empty())
        {
            auto temp=st.top();
            s+=temp;
            st.pop();
        }
        for(auto it: t){
            if(it=='#' && !st.empty())
                st.pop();
            else if(it=='#' && st.empty())
                continue;
            else
                st.push(it);
        }
        t="";
        while(!st.empty())
        {
            auto temp=st.top();
            t+=temp;
            st.pop();
        }
        return (s==t);
    }
};