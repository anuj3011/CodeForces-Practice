class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n=chalk.size();
        vector<long> prefixSum(n,0);
        prefixSum[0]=chalk[0];
        for(int i=1;i<n;i++){
            prefixSum[i]=prefixSum[i-1]+chalk[i];
        }
        k= k % prefixSum[n-1];
        int low=0,end=n-1;
        while(low<=end){
            int mid= low + (end - low)/2;
            if(prefixSum[mid]<=k)
                low=mid+1;
            else
                end=mid-1;
        }
        return low;
    }
};