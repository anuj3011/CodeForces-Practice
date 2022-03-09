// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int nums[], int n)  { 
	    // Your code goes here
	    int sum=0;
        for(int i=0;i<n;i++){
            sum+=abs(nums[i]);
        }
        vector<vector<bool>> dp(n,vector<bool>(sum+1,false));
        for(int i=0;i<n;i++) dp[i][0]=true;
        if(nums[0]<=sum) dp[0][nums[0]]=true;
        for(int i=1;i<n;i++){
            for(int k=1;k<=sum;k++){
                bool notTake=dp[i-1][k];
                bool take=false;
                if(nums[i]<=k){
                    take=dp[i-1][k-nums[i]];
                }
                dp[i][k]=take||notTake;
            }
        }
        int ans=INT_MAX;
        for(int j=0;j<=sum;j++){
            // cout<<j<<" "<<dp[n-1][j]<<endl;
            if(dp[n-1][j]){
                ans=min(ans,abs(sum-j-j));
            }
        }
        return ans;
	} 
	
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends