class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //map to store the number and count
        unordered_map<int, int> freq;
        //traverse nums and store the frequency of numbers
        for(auto it: nums){
            freq[it]++;
        }
        //take a priority queue to store the count, number
        priority_queue<pair<int, int>> pq;
        //push all from the freq map into the pq
        for(auto it: freq){
            int count = it.second;
            int number = it.first;

            pq.push({count, number});
        }
        //final ans vector
        vector<int> ans;
        //top k frequent elements
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();

        }
        return ans;
    }
};
