class Solution {
public:

    string encode(vector<string>& strs) {
            //take string and store size # and string
        string res;
        for(auto s: strs){
            res += to_string(s.size()) + '#' + s;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        while(i< s.size()){
            //find position of #
            int j = i;
            while(s[j] != '#'){
                j++;
            }

            //length of curr string when j = #
            int len = stoi(s.substr(i, j-i));
            //move to first char after #
            j++;

            //Extract actual word
            string word = s.substr(j, len);

            result.push_back(word);

            //move pointer to next encoded string;
            i = j+len;
        }
        return result;
    }
};
