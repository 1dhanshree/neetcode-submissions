class Solution {
    public int longestConsecutive(int[] nums) {
        //Store all numbers for fast lookup O(1)
        HashSet<Integer> set = new HashSet<>();
        for(int num : nums){
            set.add(num);
        }

        int longest = 0;
        //check every unique number

        for(int num: set){
            //If previous number exists, this is Not the start of sequence
            if(set.contains(num-1)){
                //skip it because we will start from the actual start
                continue;
            }

            int currNum = num;
            int currLen = 1;

            //Keep extending the sequence while the next number exists
            while(set.contains(currNum +1)){
                currNum++;
                currLen++;
            }
            //Update the longest sequence found so far
            longest = Math.max(currLen, longest);
        }
        
        return longest;
    }
}
