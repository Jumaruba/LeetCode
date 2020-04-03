//The thing is to realize that you can make a xor to find the answer 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0; 
        for (int i = 0; i < nums.size(); i++){
            ans ^= nums[i]; 
        }
        return ans; 
    }
};
/**
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = -1; 
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == -1) continue; 
            for (int j = i+1; j< nums.size(); j++){
                if (nums[i] == nums[j]){
                    nums[i] = -1; 
                    nums[j] = -1; 
                    break; 
                }
                if (j == nums.size()-1) ans = nums[i]; 
            }
            if (ans != -1) return ans; 
        }
        return nums[nums.size()-1]; 
    }
};**/
