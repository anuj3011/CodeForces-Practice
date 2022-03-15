class Solution {
public:
    int f(int i, int j, string &s, string &t,
            vector<vector<int>> &dp){
        if(j<0) return 1; //found all elements of t
        if(i<0) return 0; // Checked all elements of s but still                                    elemnets in t are left
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j])
            return dp[i][j]= f(i-1,j-1,s,t,dp) + f(i-1,j,s,t,dp);
        else 
            return dp[i][j]=f(i-1,j,s,t,dp);
    }
    
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return f(n-1,m-1,s,t,dp);
    }
};