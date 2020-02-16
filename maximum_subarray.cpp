class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> best_sub(nums.size(), 0); 
        if (nums.size() == 0) return 0; 
        best_sub[0] = nums[0]; 
        int total = best_sub[0]; 
        for (int i = 1; i < nums.size(); i++){
            best_sub[i] = best_sub[i-1] + nums[i] > nums[i]?  best_sub[i-1] + nums[i]: nums[i]; 
            total = best_sub[i] > total? best_sub[i] : total; 
        }
        return total; 
    }
    
};
