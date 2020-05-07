class Solution {
public:
    int jump(vector<int>& nums) {
        
        int curPos = 0, i = 0, prePos, n = nums.size(), level = 0; 
        
        while(curPos < n-1){
            level++; 
            prePos = curPos; 
            for (; i<= prePos; i++){
                curPos = max(nums[i] + i, curPos); 
            }
        }
        return level; 
    }
};
