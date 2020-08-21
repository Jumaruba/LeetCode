class Solution {
public:
    vector<int> candidates_ ; 
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> combinations; 
        candidates_ = candidates; 
        int cur = 0; 
        vector<int> temp; 
        

        back_tracking(combinations, target, cur, temp); 
        
        return combinations; 
    } 
    
    void back_tracking(vector<vector<int>>& combinations, int sum, int cur, vector<int>& temp){
        if (sum == 0){
            combinations.push_back(temp); 
            return; 
        }
        if (cur >= candidates_.size() || sum < 0) return; 
        
       while (cur < candidates_.size()){
           temp.push_back(candidates_[cur]); 
           back_tracking(combinations, sum - candidates_[cur], cur, temp); 
           temp.pop_back(); 
           cur++; 
       }

          
    }
};
