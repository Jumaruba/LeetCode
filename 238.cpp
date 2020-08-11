class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int> ans(nums.size()); 
        int ida = 1; 
        for (int i = 1 ; i< nums.size(); i++){
            ida *= nums[i-1]; 
            ans[i] = ida; 
        }
        int volta = 1; 
        for (int i = nums.size()-2; i >= 0; i--){
            volta*= nums[i+1]; 
            ans[i] *= volta; 
        }
        
        ans[0] = volta; 
        return ans; 
    }
};
