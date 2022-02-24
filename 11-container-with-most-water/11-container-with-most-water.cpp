class Solution {
public:
    int maxArea(vector<int>& height) {
        int j=height.size()-1;
        int i=0;
        int maxArea=INT_MIN,curr_a,min_h;
        int lh,rh;
        while(i<j){
            lh=height[i];
            rh=height[j];
            min_h=min(lh,rh);
            curr_a=(j-i)*min_h;
            maxArea=max(curr_a,maxArea);
            if(lh<rh){
                i++;
            }else
                j--;
        }
        return maxArea;
    }
};