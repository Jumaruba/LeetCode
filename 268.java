import java.util.Collections; 
class Solution {
    public int missingNumber(int[] nums) {
        int supposed = (nums.length+1)*nums.length/2; 
        int total = 0; 
        for (int i = 0 ; i < nums.length; i++)
            total += nums[i]; 
        
        return supposed-total; 
            
    }
}