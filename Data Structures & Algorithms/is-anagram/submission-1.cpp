class Solution {
public:
    bool isAnagram(string s, string t) {
        //if the length is not same they can't be anagrams at all
        if(s.size()!= t.size()) return false;

        //take a freq array of size 25 starting from 0 to map the alphabets
        vector<int> freq(26, 0);        

        //if an alphabet appears increase it's index like if a appears 5 times s[a] = 5;
        for(char c: s){
            freq[c - 'a']++;
        }

        //now decrease the alpabet's index if a appears 5 times in t[a] = 0; until last all the indexes should be zero than we can say it's an anagram
        for(char c: t){
            freq[c - 'a']--;
        }

        //check if all indexes are 0 
        for(int count : freq){
            //if not return false because there is an imbalance 
            if(count!= 0){
                return false;
            }
        }
        //return true they are anagrams
        return true;
    }
};


/*
What is 'a' doing here?

Characters have ASCII values under the hood.

Character	ASCII value
'a'	97
'b'	98
'c'	99
...	...

So:
'c' - 'a' = 99 - 97 = 2

That means:
'a' - 'a' = 0
'b' - 'a' = 1
'c' - 'a' = 2
...
'z' - 'a' = 25

This converts a letter into an index.



*/
