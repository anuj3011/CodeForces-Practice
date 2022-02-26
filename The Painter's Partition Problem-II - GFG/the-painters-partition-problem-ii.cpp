// { Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
#define ll long long
class Solution
{
  public:
  
   bool isValid(int mx,ll n,ll m,int arr[]){
        ll sum=0,count=1;
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
    
    long long minTime(int arr[], int n, int m)
    {
        // code here
        // return minimum time
        // if(n<m) return -1;
        int mx=INT_MIN;
        ll sum=0,res=-1;
        for(int i=0;i<n;i++){ 
            mx=max(mx,arr[i]);
            sum+=arr[i];
        }
        long long start=mx,end=sum;
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

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}  // } Driver Code Ends