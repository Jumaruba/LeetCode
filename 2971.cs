public class Solution {
    public long LargestPerimeter(int[] nums) {
        if (nums.Length < 3) return -1; 
        Array.Sort(nums); 
        long s = 0; 
        for (int i= 0 ; i < nums.Length-1; i++){
            s += nums[i]; 
        }
        for (long end = nums.Length-1 ; end >= 0; end--){
            if (nums[end] >= s && end!= 0) s -= nums[end-1]; 
            else if (end == 0) return -1;
            else return s + nums[end]; 
        }
        return -1; 
    }
    
}
