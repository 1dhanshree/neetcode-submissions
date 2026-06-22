class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //use two pointer appraoch 
        //use start and end pointer
        int start = 0, end = numbers.size()-1;
        while(start<end){
            //if sum of two pointers is equal to sum and they are not equal
            int sum = numbers[start] + numbers[end];
            if(sum == target && numbers[start]!= numbers[end]){
                return {start+1, end+1};
            }else if(sum < target){
                start++;
            }
            else{
                end--;
            }
        }
        return {};
    }
};
