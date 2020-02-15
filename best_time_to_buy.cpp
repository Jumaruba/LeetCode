class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int lowest = prices[0]; 
        int solution = 0; 
        for (int i = 1; i < prices.size(); i++){
            if (prices[i] - lowest > solution) solution = prices[i] - lowest; 
            if (prices[i] < lowest) lowest = prices[i]; 
        }
        return solution; 
    }
};
