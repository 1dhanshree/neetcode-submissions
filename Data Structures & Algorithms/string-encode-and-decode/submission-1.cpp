class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(auto st: strs){
            res += to_string(st.size()) + '#' + st;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;

        while(i< s.size()){
            int j = i;
            //track #
            while(s[j] != '#'){
                j++;
            }

            //get length of the encoded word
            int len = stoi(s.substr(i, j-i));
            //move j to word 
            j++;
            //get actual word which is encoded
            string word = s.substr(j, len);

            result.push_back(word);

            i = j+len;
            
        }
        return result;
    }
};
