class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.size() == 0) return 0; 
        vector <int> v(nums.size() +1, 0); 
        for (int i = 0 ; i < nums.size() ; i++) v[i+1] = nums[i] + v[i]; 
        if (v[v.size() -1] < s) return 0; 
        int length = nums.size() ; 
        int init = 0;  
        for (int i = 0 ; i < nums.size(); i++){
            while(v[i+1] - v[init] >= s){
                init ++; 
                length = (i+1)-init + 1; 
            }
            if ((i+1)-init >= length-1) init ++; 
        }
        return length; 
    }
};
