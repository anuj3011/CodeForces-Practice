// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        int maxL[n];
        maxL[0]=arr[0];
        for(int i=1;i<n;i++)
            maxL[i]=max(maxL[i-1],arr[i]);
        int maxR[n];
        maxR[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--)
            maxR[i]=max(maxR[i+1],arr[i]);
        long long water[n];
        for(int i=0;i<n;i++){
            water[i]=min(maxR[i],maxL[i])-arr[i];
        }
        long long res=0;
        for(int i=0;i<n;i++)
            res+=water[i];
        return res;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends