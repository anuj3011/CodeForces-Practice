class Solution {
public:
    int findWays(string& s, int i, vector<int> &dp){
        if(i>=s.length()) 
            return 1;
        if(dp[i]!=-1) return dp[i];
        int dig1=s[i]-'0';
        int dig2=0;
        int ans=0;
        if(i<s.length()-1)
            dig2= dig1*10 +(s[i+1]-'0');
        if(dig1>0)
            ans+=findWays(s,i+1,dp);
        if(dig1>0 && dig2>0 && dig2<27)
            ans+=findWays(s,i+2,dp);
        return dp[i]=ans;
    }
    
    int numDecodings(string s) {
        vector<int> dp(101,-1);
        return findWays(s,0,dp);
    }
};