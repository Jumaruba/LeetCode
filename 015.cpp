class Solution {
public:  
    
    vector<vector<int>> ans; 
    void twosum(vector<int>&nums, int target, int begin){
        int lp = begin, rp = nums.size() -1; 
        if (nums[begin] > target) return ; 
        while (lp < rp) {

            while ( lp < rp && (nums[lp] + nums[rp] < target || (lp != begin &&nums[lp] == nums[lp-1] )) )  lp++;  
            while( lp < rp && (nums[lp] + nums[rp] > target || (rp != nums.size() -1 && nums[rp] == nums[rp+1])))  rp--;  
            if (lp >= rp) return; 
            if (nums[lp] + nums[rp] == target ) {
                ans.push_back({nums[lp], nums[rp], -target}); 
                lp++; 
                rp --; 
            }
            
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) { 
        if (nums.size() < 3 ) return {}; 
        sort(nums.begin(), nums.end());  
        int i = 1; 
        twosum(nums, -nums[0], i); 
        
        for (i ; i < nums.size() -2; i++){
            if (nums[i] != nums[i-1]){
                twosum(nums, -nums[i], i+1);          
            }
        } 
        
        return ans; 
    } 
};
