class Solution {
public:
    bool canJump(vector<int>& nums) {
        int m = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > m) return false; 
            m = max(m, i + nums[i]); 
        } 
        return true; 
    }
};
