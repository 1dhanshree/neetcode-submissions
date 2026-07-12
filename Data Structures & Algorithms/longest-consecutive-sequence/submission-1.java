class Solution {
    public int longestConsecutive(int[] nums) {
        //store all the values in a Hashset
        HashSet<Integer> set = new HashSet<>();
        for(int n : nums){
            set.add(n);
        }

        int ans = 0;

        //check for every unique element
        for(int n : set){
            //If Previous number exists it's not the start
            if(set.contains(n-1)){
                //skip it because we will start from beginning number
                continue;
            }

            int currNum = n;
            int currLen = 1;

            //Keep extending the sequence until the next umber exists
            while(set.contains(currNum+1)){
                currNum++;
                currLen++;
            }
            //Update the answer
            ans = Math.max(ans, currLen);
        }
        return ans;
    }
}
