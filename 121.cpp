class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m = 0, buy = prices[0]; 
        for (int i =  1; i < prices.size(); i++) { 
            if (prices[i] < buy)  buy = prices[i]; 
            m = max(prices[i] - buy, m); 
        } 

        return m; 
    }
}
