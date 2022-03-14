class Solution {
public:
    int lcs(int ind1, int ind2, string &s, string &t,                               vector<vector<int>> &dp){
        if(ind1<0 || ind2<0) return 0;
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        if(s[ind1]==t[ind2])
            return dp[ind1][ind2]= 1+ lcs(ind1-1,ind2-1,s,t,dp);
        return dp[ind1][ind2]= max(lcs(ind1-1,ind2,s,t,dp),                                                lcs(ind1,ind2-1,s,t,dp));
    }
    
    int longestPalindromeSubseq(string s) {
        string t=s;
        reverse(s.begin(),s.end());
        int n=s.length();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return lcs(n-1,n-1,s,t,dp);
    }
};