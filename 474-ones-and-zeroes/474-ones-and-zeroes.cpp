class Solution {
public:
    int dp[101][101][601];
    vector<int> freqcount(string s)
    {
        vector<int> f(2,0);
        for(auto i:s)
        {
            if(i=='0')
                f[0]++;
            else
                f[1]++;
        }
        return f;
    }
    
    //memoization
    int helper(vector<string>& s,int m,int n,int idx,vector<vector<int>> freq)
    {
        if(idx>=s.size() || (m+n)<=0)
            return 0;
        if(dp[m][n][idx]!=-1)
            return dp[m][n][idx];
        //retrive freq count of zero and 1 in cur ele
        int zero=freq[idx][0];
        int one=freq[idx][1];
        //case1-if curr ele included
        int case1=0;
        if(zero<=m && one<=n)
            case1=1+helper(s,m-zero,n-one,idx+1,freq);
        //case2-if curr ele excluded
        int case2=0;
        case2=helper(s,m,n,idx+1,freq);
        
        return dp[m][n][idx]=max(case1,case2);
    }
    
    
    int findMaxForm(vector<string>& s, int m, int n) {
        //memset(dp,-1,sizeof(dp));
        
        //count freq of one and zero
        vector<vector<int>> freq(s.size(),vector<int>(2,0));
        for(int i=0;i<s.size();i++)
        {
            freq[i]=freqcount(s[i]);
        }
        //tabulation
        vector<vector<int>> v(m+1,vector<int>(n+1,0));
        for(int i=0;i<s.size();i++)
        {
            int zero=freq[i][0];
            int one=freq[i][1];
            for(int j=m;j>=zero;j--)
            {
                for(int k=n;k>=one;k--)
                {
                    v[j][k]=max(v[j][k],1+v[j-zero][k-one]);
                }
            }
        }
        
        return v[m][n];
    }
};