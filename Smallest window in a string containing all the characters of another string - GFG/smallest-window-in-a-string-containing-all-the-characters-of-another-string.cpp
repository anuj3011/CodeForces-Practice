// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string t)
    {
        // Your code here
        unordered_map<char,int> map;
        for(int i=0;i<t.length();i++){
            map[t[i]]++;
        }
        int count=map.size();
        int i=0,j=0;
        int k=INT_MAX;
        int ans_i=-1,ans_j=-1;
        while(j<s.length()){
            if(map.find(s[j])!=map.end()){
                map[s[j]]--;
                if(map[s[j]]==0){
                    count--;
                }
            }
            if(count>0){
                j++;
            }
            else if(count==0){
                while(count==0){
                    if(map.find(s[i])!=map.end()){
                        map[s[i]]++;
                        if(map[s[i]]>0) count++;
                    }
                    i++;
                }
                // cout<<i<<" "<<j<<endl;
                if(j-i<k){
                    ans_i=i-1;
                    ans_j=j;
                    k=j-i;
                    // cout<<ans_i<<" "<<ans_j;
                }
                j++;
            }
        }
        string ans="";
        if(k==INT_MAX)
            return "-1";
        else
        {
            for(int i=ans_i;i<=ans_j;i++){
                ans.push_back(s[i]);
            }
            return ans;
        }
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends