class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //initially the sum and ans will be 0;
        int sum = 0;
        int ans = INT_MIN;
        //traverse the array
        for(int i = 0; i<nums.size(); i++){
            //extend the sum
            sum+= nums[i];
            //update the max ans
            ans = max(sum, ans);
            //if sum becomes negative, simply set to 0,, because negative sum will affect answer
            if(sum < 0) sum = 0;
        }
        return ans;
    }
};
