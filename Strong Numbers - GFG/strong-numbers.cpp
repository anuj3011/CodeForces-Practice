// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int isStrong(int N) {
        // code here
        int fact[10];
        fact[0]=1;
        for(int i=1;i<10;i++){
            fact[i]=i*fact[i-1];
        }
        int sum=0;
        int n=N;
        while(n>0){
            int rem=n%10;
            sum+=fact[rem];
            n=n/10;
        }
        return (N==sum);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.isStrong(N) << endl;
    }
    return 0;
}  // } Driver Code Ends