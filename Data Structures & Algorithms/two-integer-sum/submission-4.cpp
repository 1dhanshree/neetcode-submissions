class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //take a map to store the elements and indices
        unordered_map<int,int> mpp;
        // traverse the whole array
        for(int i = 0; i<nums.size(); i++){
            //calc the complement
            int comp = target - nums[i];
            //check if comp is present in map
            if(mpp.count(comp)){
                return {mpp[comp], i};
            }
            //add the current element in map
            mpp[nums[i]] = i;
        }
        return {};
    }
};
