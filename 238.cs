// Uses prefix and sufix Multiplication (From PrefixSum algo)
public class Solution {
    public int[] ProductExceptSelf(int[] nums) {
        var sufixMul = new int[nums.Length]; 
        var prefixMul = new int[nums.Length]; 
        var ans = new int[nums.Length]; 
        sufixMul[0] = nums[nums.Length-1];
        prefixMul[0] = nums[0]; 

        // Compute sufixPos and PrefixPos; 
        var sufixPos = 0; 
        for (var i = 1; i < nums.Length; i++){
            sufixPos = nums.Length-1-i;
            sufixMul[i] = nums[sufixPos] * sufixMul[i-1]; 
            prefixMul[i] = nums[i] * prefixMul[i-1]; 
        }
        
        // Store the answer for the first and the last value; 
        ans[nums.Length-1] = prefixMul[nums.Length-2];  
        ans[0] = sufixMul[nums.Length-2]; 

        // Compute the answer for the values in the middle of nums. 
        for (var i = 1; i < nums.Length-1; i++){
            sufixPos = nums.Length-1-i; 
            ans[i] = prefixMul[i-1] * sufixMul[sufixPos-1];
        }

       return ans; 
    }
}
