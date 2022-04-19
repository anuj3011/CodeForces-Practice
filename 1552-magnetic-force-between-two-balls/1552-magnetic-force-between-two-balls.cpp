class Solution {
public:
    bool isPossible(vector<int> arr, int m, int mid){
        int lastPos=arr[0],count=1;
        for(int i=1;i<arr.size();i++){
            if(arr[i]-lastPos>=mid){
                lastPos=arr[i];
                count++;
            }
            if(count==m) return true;
        }
        return false;
    }
    
    int maxDistance(vector<int>& position, int m) {
        int n=position.size();
        sort(position.begin(),position.end());
        int low=0,high=position[n-1];
        int ans=-1;
        while(low<=high){
            int mid= low+(high-low)/2;
            if(isPossible(position,m,mid)){
                low=mid+1;
                ans=mid;
            }else{
                high=mid-1;
            }
        }
        return ans;
    }
};