class Solution {
    public int maxProduct(int[] nums) {
        int M = nums[0], cM = 1, m = 1, t; 
        
        for (int n: nums){
            t = cM; 
            cM = Math.max(n, Math.max(cM*n, m*n)); 
            m = Math.min(n, Math.min(m*n, t*n)); 
            M = Math.max(M, cM); 
            
        }
        
        return M; 
        
 
    }
}
