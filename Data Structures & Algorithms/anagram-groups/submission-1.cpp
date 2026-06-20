class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //map to store the key and vector
        unordered_map<string, vector<string>> mp;

        //traverse the strs vector
        for(auto st : strs){
            //make copy of st
            string key = st;
            //sort key
            sort(key.begin(), key.end());
            //push st into the map according to the key
            mp[key].push_back(st);
        }
        //final answer vector
        vector<vector<string>> ans;
        for(auto it: mp){
            //push all vectors in the ans
            ans.push_back(it.second);
        }

    return ans;
    }
};
