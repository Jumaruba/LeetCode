class Solution {
    HashSet<Integer> hash = new HashSet<>(); 
    public int longestConsecutive(int[] nums) {
        
        // add all elements to the hash 
        for (int i = 0 ; i < nums.length; i++){
            hash.add(nums[i]); 
        }
        
        int longestSeq = 0; 
        for (int num: nums){
            int currentSeq = 1; 
            if (hash.contains(num-1) == false){
                while(hash.contains(num+currentSeq)){
                    currentSeq ++; 
                }
                
            }
            longestSeq = Math.max(currentSeq, longestSeq); 
        }
        
        return longestSeq; 
    }
    
}