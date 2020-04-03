class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0; 
        int best_now = nums[0]; 
        int best = nums[0]; 
        for (int i = 1; i < nums.size(); i++){
            if (best_now < 0) best_now = 0; 
            best_now += nums[i]; 
            best = best_now > best ? best_now: best; 
            
        }
        return best; 
    }
    
};
