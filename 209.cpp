class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.size() == 0) return 0; 
        nums.insert(nums.begin(), 0); 
        for (int i = 1 ; i < nums.size(); i++) nums[i] += nums[i-1] ; 
        
        if (nums[nums.size() -1] < s) return 0; 
        int length = nums.size() -1; 
        int init = 0;  
        for (int i = 0 ; i < nums.size()-1; i++){
            while(nums[i+1] - nums[init] >= s){
                init ++; 
                length = (i+1)-init + 1; 
            }
            if ((i+1)-init >= length-1) init ++; 
        }
        return length; 
    }
};
