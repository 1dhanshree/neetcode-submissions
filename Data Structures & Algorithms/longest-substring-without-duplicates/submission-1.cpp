class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        char left = 0;
        int maxl = 0;

        for(int i = 0; i<s.size(); i++){
            while(seen.count(s[i])){
                seen.erase(s[left]);
                left++;
            }
            maxl = max(maxl, i - left +1);
            seen.insert(s[i]);
        }
        return maxl;

    }
};
