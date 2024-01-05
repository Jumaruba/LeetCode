 public class Solution {
    public int LengthOfLIS(int[] nums) {
        int[] res = new int[nums.Length]; 
        res[0] = 1; 
        var answer = 1; 
        for (var i = 1; i < nums.Length; i++){
            var value = 1; 
            for (var j = 0; j < i; j++){
                if (nums[i] > nums[j]) {
                    value = Math.Max(value, res[j]+1); 
                }
            }   
            res[i] = value; 
            answer = Math.Max(value, answer); 
        }
        return answer;
    }
}
