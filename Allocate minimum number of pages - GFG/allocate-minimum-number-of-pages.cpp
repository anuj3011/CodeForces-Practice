// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool isValid(int mx,int n,int m,int arr[]){
        int sum=0,count=1;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum>mx){
                count++;
                sum=arr[i];
            }
            if(count>m)
                return false;
        }
        return true;
    }
    
    int findPages(int arr[], int n, int m) 
    {
        //code here
        if(n<m) return -1;
        int mx=INT_MIN,sum=0,res=-1;
        for(int i=0;i<n;i++){ 
            mx=max(mx,arr[i]);
            sum+=arr[i];
        }
        int start=mx,end=sum;
        while(start<=end){
            int mid= start + (end-start)/2;
            if(isValid(mid,n,m,arr))
            {
                res=mid;
                end=mid-1;
            }else
                start=mid+1;
        }
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends