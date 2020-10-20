class Solution {
public:
    string minWindow(string s, string t) {
        int left=0,right=0;
        unordered_map<char,int>m;
        for(char c:t){
            m[c]++;
        }
        int count=t.length();
        int l=INT_MAX;
        int temp=0;
        while(right<s.length()){
            if(m[s[right]]>0){
                count--;   
               // cout<<count<<endl;
            }
            m[s[right]]--;
            right++;
            
            while(count==0){
                if(l>right-left){
                    l=right-left;
                    temp=left;
                    
                }
                m[s[left]]++;
                if(m[s[left]]>0){
                    count++;
                    //cout<<count<<endl;
                }
                left++;
                
            }
        }
        if(l!=INT_MAX)
        return s.substr(temp, l);
        return "";
        
    }
};
