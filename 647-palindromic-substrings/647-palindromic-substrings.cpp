class Solution {
public:
    int countSubstrings(string s) {
    int len = s.size();
    int dp[len][len];
    memset(dp,0, sizeof dp);
    int start = 0;
    int end = 1;
    int count = 0;
    for(int i = 0; i < len; i++)
    {
        dp[i][i] = 1;
        count++;
    }
    for(int i = 0; i < len - 1; i++)
    {
        if(s[i] == s[i + 1])
        {
            dp[i][i + 1] = 1;
            count++;
        }
    }
    for(int j = 2; j < len; j++)
    {
        for(int i = 0; i < len - j; i++)
        {
            int left = i;
            int right = i + j;
            if(s[left] == s[right] && dp[left + 1][right - 1])
            {
                dp[left][right] = 1;
                count++;
            }
        }
    }
    return count; 
}
};