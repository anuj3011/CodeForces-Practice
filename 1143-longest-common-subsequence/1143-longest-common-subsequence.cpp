class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int ind1=text1.length()-1;
        int ind2=text2.length()-1;
        vector<vector<int>> dp(ind1+1,vector<int>(ind2+1,-1));
        return f(ind1,ind2,text1,text2,dp);
    }
    
    int f(int ind1,int ind2, string &s1, string                                  &s2,vector<vector<int>>&dp){
        if(ind1<0 || ind2<0)
            return 0;
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        if(s1[ind1]==s2[ind2])
            return dp[ind1][ind2]= 1+ f(ind1-1,ind2-1,s1,s2,dp);
        int moveFirst= f(ind1-1,ind2,s1,s2,dp);
        int moveSecond= f(ind1,ind2-1,s1,s2,dp);
        return dp[ind1][ind2]= max(moveFirst,moveSecond);
    }
};