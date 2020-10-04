/*In this code we have group a atring contain same character for that I stored each word of same character
in a map then copied elements of that map into a new vector of string*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>m;
         vector<vector<string>>result;
        for(string s:strs){
            string temp=s;
            sort(s.begin(),s.end());
            m[s].push_back(temp);
        }
        unordered_map<string,vector<string>>::iterator it;
        for(it=m.begin();it!=m.end();it++){
            result.push_back(it->second);
        }
       
        return result;
    }
};
