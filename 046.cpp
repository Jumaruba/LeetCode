class Solution {
public:
    vector<int> nums_; 
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> combinations; 
        nums_ = nums;  
 
        combinations.push_back(nums_); 
        backtracking(combinations, 0); 
 
        return combinations; 
        
    }
    
    void backtracking(vector<vector<int>>& combinations, int cur){
        
        if (cur +1 < nums_.size()) backtracking(combinations, cur+1);
        for (int i = cur; i < nums_.size()-1; i++){
            swap(nums_[cur], nums_[i+1]);
            combinations.push_back(nums_); 
            backtracking(combinations, cur+1); 
            swap(nums_[cur], nums_[i+1]);   
        }
        
    }
        
};
