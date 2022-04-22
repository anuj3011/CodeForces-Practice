class Solution {
public:
    int minimumMountainRemovals(vector<int>& arr) {
        int n=arr.size();
        vector<int> dp1(n,1),dp2(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[i]>arr[j] && 1+dp1[j]>dp1[i]){
                    dp1[i]=1+dp1[j];
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>i;j--){
                if(arr[i]>arr[j] && 1+dp2[j]>dp2[i]){
                    dp2[i]=1+dp2[j];
                }
            }
        }
        int ans=1;
        for(int i=0;i<n;i++){
            cout<<dp1[i]<<" "<<dp2[i]<<endl;
            if(dp1[i]>1 && dp2[i]>1)
                ans=max(ans,dp1[i]+dp2[i]-1);
            // cout<<ans<<endl;
        }
        return (n-ans);
    }
};