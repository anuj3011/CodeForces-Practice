class Solution {
public:
    bool isValid(vector<int> time, long long mid, int totalTrips){
        // int count=0;
        long long sum=0;
        for(int i=0;i<time.size();i++){
            long long temp=time[i];
            sum+= mid/temp;
        }
        return (sum>=totalTrips);
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        // int mx=-1;
        long long sum=0;
        for(int i=0;i<time.size();i++){
            // mx=max(mx,time[i]);
            sum+=time[i];
        }
        long long i=1,j=1e14;
            long long res=0;
        while(i<=j){
            long long mid=i+(j-i)/2;
            if(isValid(time,mid,totalTrips)){
                j=mid-1;
                res=mid;
            }else{
                i=mid+1;
            }
        }
        return res;
    }
};