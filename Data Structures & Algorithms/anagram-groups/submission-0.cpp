class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //map to store key and vector of strings
        unordered_map<string, vector<string>> mp;
        //traverse the each string and 
        for(auto st : strs){
            //make copy of original string to use as key
            string key = st;
            //sort key
            sort(key.begin(), key.end());
            //push original st into the hasmap
            mp[key].push_back(st);
            
        }
        //final answer vector
        vector<vector<string>> ans;
        for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
