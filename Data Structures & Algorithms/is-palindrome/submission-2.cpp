class Solution {
public:
    bool isPalindrome(string s) {
        //two pointer approach
        //start and end pointers
        int start = 0, end = s.size()-1;
        while(start<=end){
            //skip if it is not character or number
            if(!isalnum(s[start])){
                start++; 
                continue;
            } 
            if(!isalnum(s[end])){
                end--; 
                continue;
            } 
            //check if they are same
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
