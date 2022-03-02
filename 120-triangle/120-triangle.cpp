class Solution {
public:
    int f(int i,int j, int n,
          vector<vector<int>>&triangle,vector<vector<int>> &dp){
        if(i == n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int below= triangle[i][j]+ f(i+1,j,n,triangle,dp);
        int right= triangle[i][j] + f(i+1,j+1,n,triangle,dp);
        return dp[i][j]=min(below,right);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int i=0,j=0;    //i represent row, j represent column
        vector<vector<int>> dp;
        for(int i=0;i<n;i++){
            vector<int> temp(triangle[i].size(),-1);
            dp.push_back(temp);
        }
        return f(i,j,n,triangle,dp);
    }
    
};