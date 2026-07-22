class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //initially buying and profit is 0
        int buy = prices[0];
        int profit = 0;
        //traverse the array
        for(int i = 0; i<prices.size(); i++){
            //calc the curr day cost
            int cost = prices[i] - buy;
            //update the profit
            profit = max(cost, profit);
            //update the buying d
            buy = min(prices[i], buy);
        }
        return profit;
    }
};
