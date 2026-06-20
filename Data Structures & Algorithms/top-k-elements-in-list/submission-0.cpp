class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //store the number and freq in map
        unordered_map<int, int> freq;
        //store the freq of each number
        for(auto it: nums){
            freq[it]++;
        }
        //take priority queue store count and number
        priority_queue<pair<int, int>> q;
        for(auto it : freq){
            int count = it.second;
            int number = it.first;

            q.push({count, number});
        }
        //final vector to store the ans
        vector<int> ans;
        //return top k elements

        while(k--){
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }
};
