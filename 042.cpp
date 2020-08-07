class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        nums.push_back(0); 
        for (int i = 0 ; i <nums.size(); i++) nums[i] = nums[i] > nums.size() || nums[i] <= 0 ? 0: nums[i]; 
        for (int i = 0 ; i< nums.size(); i++)
             nums[nums[i]%nums.size()] += nums[nums[i]%nums.size()] == 0 ? 2*nums.size() : nums.size(); 
        
        for (int i = 1 ; i < nums.size(); i++){
  
            if (nums[i] <= int(nums.size())) return i; 
        }
       
        return nums.size(); 
    }
};
