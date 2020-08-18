class Solution {
public:
    vector<int> candidates_ ; 
    int target_;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> combinations; 
        target_ = target; 
        candidates_ = candidates; 
        int cur = 0; 
        vector<int> temp; 
        
        back_tracking(combinations, 0 , cur+1, temp); 
        back_tracking(combinations, candidates[0], cur, {candidates[0]}); 
        
        vector<vector<int>> ans; 
        for (auto it = combinations.begin() ; it != combinations.end() ; it++)
            ans.push_back(*it); 
        
        return ans; 
    } 
    
    void back_tracking(set<vector<int>>& combinations, int sum, int cur, vector<int> temp){

        if (sum == target_){
            combinations.insert(temp); 
            return; 
        }
        if (cur >= candidates_.size() || sum > target_) return; 
        
        back_tracking(combinations, sum, cur+1, temp); 
        while(sum < target_){
            temp.push_back(candidates_[cur]); 
            sum+= candidates_[cur]; 
            back_tracking(combinations, sum, cur+1, temp); 
        }
          
    }
};
