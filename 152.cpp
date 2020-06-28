class Solution {
public:
    int comp(int a, int b){
        return a<b; 
    }
    int maxProduct(vector<int>& nums) {
        int maxLocal = nums[0]; 
        int minLocal = nums[0]; 
        int maxProduct = nums[0]; 
        
        for (int i = 1 ; i< nums.size(); i++){
            int temp = maxLocal; 
            maxLocal = max({nums[i], maxLocal*nums[i], minLocal*nums[i]}); 
            minLocal = min({nums[i], temp*nums[i], minLocal*nums[i]}); 
            maxProduct = max(maxLocal, maxProduct); 
        }
        
        return maxProduct; 
    }
};
