class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> results(cost.size(),0); 
        results[0] = cost[0]; 
        results[1] = cost[1];  
        for (int i = 2; i < results.size(); i++){
            results[i] = cost[i] + min(results[i-2], results[i-1]); 
        }
        
        return min(results[cost.size()-1], results[cost.size()-2]); 
    }
};
