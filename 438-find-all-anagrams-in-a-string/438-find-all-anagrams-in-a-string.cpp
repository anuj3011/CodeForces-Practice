class Solution {
public:
    vector<int> findAnagrams(string txt, string pat) {
        unordered_map<char,int> m;
	    int i=0,j=0;
        vector<int> ans;
	    for(int i=0;i<pat.length();i++){
	        m[pat[i]]++;
	    }
	    int count=m.size();
	    while(j<txt.length()){
	        if(m.find(txt[j])!=m.end()){
	            m[txt[j]]--;
	            if(m[txt[j]]==0)
	                count--;
	        }
	        if(j-i+1<pat.length()){
	            j++;
	        }
	        else if(j-i+1==pat.length()){
	            if(count==0){
	                ans.push_back(i);
	            }
	            if(m.find(txt[i])!=m.end()){
	                m[txt[i]]++;
	                if(m[txt[i]]==1)
	                    count++;
	            }
	            i++;
	            j++;
	        }
	    }
	    return ans;
    }
};