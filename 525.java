class Solution {
    public int findMaxLength(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>(); 
        int total = 0; 
        int bun = 0; 
        map.put(0,-1); 
        for (int i = 0 ; i < nums.length; i++){
            total += nums[i] == 0? -1: 1; 
            if (!map.containsKey(total))
                map.put(total, i); 
            else
                bun = Math.max(bun, i-map.get(total)); 
        }
        return bun;    
    }
}
