class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> hash = new HashMap<>(); 
        
        for (int i = 0 ; i < nums.length; i++){
            int val = hash.getOrDefault(target - nums[i], 0); 
            if (val > 0){
                return new int[]{val, i+1}; 
            } else {
                val = hash.getOrDefault(nums[i], 0); 
                if (val == 0) hash.put(nums[i], i+1); 
            }
        }
        
        return new int[]{}; 
    }
}
