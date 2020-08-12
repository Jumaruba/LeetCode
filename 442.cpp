class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector <int> ans; 
        if (nums.size() == 0 || nums.size() == 1) return ans; 
        for (int i = 0 ; i < nums.size(); i++) nums[nums[i]%nums.size()] += nums.size();
        if (nums[0] > 2*nums.size()) ans.push_back(nums.size()); 
        for (int i = 1 ; i < nums.size(); i++){
            if (nums[i] > 2*nums.size()) ans.push_back(i); 
        }
        return ans; 
    }
};
