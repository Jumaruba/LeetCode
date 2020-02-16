class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> t(nums.size(),0); 
        if (nums.size() == 1) return nums[0]; 
        if (nums.size() == 2) return max(nums[0], nums[1]); 
        if (nums.size() == 0) return 0; 
        t[0] = nums[0]; 
        t[1] = max(nums[1],nums[0]); 
        for (int i = 2; i< nums.size(); i++){
            t[i] =  max(nums[i] + t[i-2], t[i-1]); 
        }
        return max(t[nums.size()-1], t[nums.size()-2]); 
    }
};
