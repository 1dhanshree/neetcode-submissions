class Solution {
public:
    bool isPalindrome(string s) {
        //take 2 pointers start and end
        int start = 0, end = s.size()-1;
        //traverse whole array
        while(start < end){
            //check if start is not alphanum
            if(!isalnum(s[start])){
                start++;
                continue;
                
            }
            //check if end is not alphanum
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
