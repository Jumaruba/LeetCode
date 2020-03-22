class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days[days.size()-1]; 
        vector<int> dp(n+1, 0); 
        vector<bool> travel(n+1, false); 
        if (days.size() == 0) return 0; 
        if (days.size() == 1) return costs[0]; 
        //setting travel 
        for (int i = 0; i < days.size(); i++) travel[days[i]] = true;
        for (int i = 1; i< n+1; i++){
            if (!travel[i]) dp[i] = dp[i-1]; 
            else{
                int one = dp[i-1] + costs[0]; 
                int seven = dp[max(i-7, 0)] + costs[1]; 
                int thirty = dp[max(i-30,0)] + costs[2]; 
                dp[i] = min(min(one,seven),thirty); 
            }
            
        }
        return dp[dp.size()-1]; 
    }
};
