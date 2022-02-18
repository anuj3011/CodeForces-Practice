class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()) return false;
        
        unordered_map<char,int> m;
        for(int i=0;i<s1.length();i++){
            m[s1[i]]++;
        }
        int count=m.size();
        int i=0,j=0;
         while(j<s2.length()){
	        if(m.find(s2[j])!=m.end()){
	            m[s2[j]]--;
	            if(m[s2[j]]==0)
	                count--;
	        }
	        if(j-i+1<s1.length()){
	            j++;
	        }
	        else if(j-i+1==s1.length()){
	            if(count==0){
	               return true;
	            }
	            if(m.find(s2[i])!=m.end()){
	                m[s2[i]]++;
	                if(m[s2[i]]==1)
	                    count++;
	            }
	            i++;
	            j++;
	        }
	    }
	    return false;
    }
};