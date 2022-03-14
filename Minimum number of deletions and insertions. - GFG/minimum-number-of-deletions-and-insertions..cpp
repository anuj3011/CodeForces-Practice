// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int lcs(int ind1, int ind2, string &s, string &t,vector<vector<int>> &dp){
        if(ind1<0 || ind2<0) return 0;
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        if(s[ind1]==t[ind2])
            return dp[ind1][ind2]= 1+ lcs(ind1-1,ind2-1,s,t,dp);
        return dp[ind1][ind2]= max(lcs(ind1-1,ind2,s,t,dp),                                                lcs(ind1,ind2-1,s,t,dp));
    }
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int n=str1.length();
	    int m=str2.length();
	    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
	    return n+m - 2*lcs(n-1,m-1,str1,str2,dp);
	    
	} 
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends