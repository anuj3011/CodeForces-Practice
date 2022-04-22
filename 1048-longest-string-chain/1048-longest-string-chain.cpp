class Solution {
public:
    bool checkPossible(string &s1,string &s2){
        if(s1.size()!=s2.size()+1){
            return false;
        }
        int first=0,second=0;
        while(first<s1.size()){
            if(second<s2.size() && s1[first]==s2[second]){
                first++;
                second++;
            }else
                first++;
        }
        if(first==s1.size() && second==s2.size())
            return true;
        return false;
    }
    
    static bool comparator(string &s1, string &s2){
        return s1.size()<s2.size();
    }
    
    int longestStrChain(vector<string> &nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        int maxi=1;
        sort(nums.begin(), nums.end(), comparator);
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(checkPossible(nums[i],nums[prev]) && dp[i]<1+dp[prev]){
                    dp[i]=dp[prev]+1;
                }
            }
            if(maxi<dp[i]){
                maxi=dp[i];
            }
        }
        return maxi;
    }
};