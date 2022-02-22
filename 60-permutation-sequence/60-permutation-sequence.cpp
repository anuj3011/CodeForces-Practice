class Solution {
public:
    string getPermutation(int n, int k) {
        int fact=1;
        vector<int> nums;
        for(int i=1;i<n;i++){
            fact*=i;        //calculating factorial
            nums.push_back(i);      //storing all the integers
        }
        nums.push_back(n);
        string s="";
        k--;            //as we are using 0 based indexing reducing k
        while(true){
            s+=to_string(nums[k/fact]);             // curr digit will be k/fact, dry run
            nums.erase(nums.begin()+k/fact);        //remove that digit from vector
            if(nums.size()==0)
                break;
            k=k%fact;                               //reduce k to find next digit
            fact/=nums.size();                      //reduce factorial to next lower                                                             //intergers fact, i.e. n! to n-1!
        }
        return s;
    }
};