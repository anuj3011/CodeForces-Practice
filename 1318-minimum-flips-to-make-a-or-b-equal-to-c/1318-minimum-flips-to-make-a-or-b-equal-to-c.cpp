class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips=0;
        int i=1;
        for(int j=0;j<32;j++){
            int d1=a&i;
            int d2=b&i;
            int d3=c&i;
            if(d3!=0){
                if(d1==0 && d2==0)
                    flips++;
            }
            
            else{
                if(d1!=0 && d2!=0)
                    flips+=2;
                else if(d1!=0 || d2!=0)
                    flips++;
            }
            i=(i& 0xffffffff)<<1;       //i&0xfffffffff <<1 is same as i<<=1; stupid cpp bug
        }
        return flips;
    }
};