// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        long long sum=0;
        priority_queue<long long,vector<long long>,greater<long long>> minh;
        for(int i=0;i<n;i++)
            minh.push(arr[i]);
        if(minh.size()==1)
            return 0;
        while(minh.size()>0){
            long long first=minh.top();
            minh.pop();
            long long second= minh.top();
            // cout<<first<<" "<<second<<endl;
            minh.pop();
            long long temp=first+second;
            sum+=temp;
            if(!minh.empty())
                minh.push(temp);
        }
        return sum;
    }
};


// { Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends