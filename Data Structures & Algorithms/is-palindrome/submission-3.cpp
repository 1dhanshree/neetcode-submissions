class Solution {
public:
    bool isPalindrome(string s) {
        //use two pointer approach
        int start = 0, end = s.size()-1;
        while(start<=end){
            //skip if it is not number of character
            if(!isalnum(s[start])){
                start++;
                continue;
            }
            if(!isalnum(s[end])){
                end--;
                continue;
            }
            //check if they are equal
            if(tolower(s[start]) != tolower(s[end])){
                return false;
            }else{
                start++;
                end--;
            }
        }
        return true;
    }
};
