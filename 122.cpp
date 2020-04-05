class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int most = 0, less = 0, total = 0;
        bool mostTurn = false, lessTurn = true; 
        for (int i = 0; i < prices.size(); i++){
            if (i == 0) less = prices[i]; 
            else if (prices[i] < less && lessTurn) less = prices[i]; 
            else if (prices[i] > less && lessTurn) {
                lessTurn = false; 
                mostTurn = true; 
                most = prices[i]; 
            }
            else if (prices[i] > most && mostTurn) most = prices[i]; 
            else if (prices[i] < most && mostTurn){
                total+= most -less; 
                mostTurn = false; 
                lessTurn = true; 
                less = prices[i]; 
            }
        }
        if (mostTurn)  total+= most - less; 
        return total; 
    }
};
