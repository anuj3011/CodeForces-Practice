// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:

bool checkSubarray(int nums[], int target,
                  int ind,vector<vector<int>> &dp){
        if(target==0) return true;
        if(ind==0) return (nums[0]==target);
        if(dp[ind][target]!=-1) return dp[ind][target];
        bool notTake= checkSubarray(nums,target,ind-1,dp);
        bool take=false;
        if(target>=nums[ind])
            take=checkSubarray(nums,target-nums[ind],ind-1,dp);
        return dp[ind][target]=take || notTake;
    }
    
    bool isSubsetSum(int n, int arr[], int k){
        // code here 
        vector<vector<int>> dp(n, vector<int>(k+1,-1));
        return checkSubarray(arr,k,n-1,dp);
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(N, arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends