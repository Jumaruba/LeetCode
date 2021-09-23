class Solution {
    public int longestCommonSubsequence(String t1, String t2) {
        int s1 = t1.length(), s2 = t2.length(); 
        int[][] m = new int[s1+1][s2+1];
            
        for (int i = 0 ; i < s1; i++){
            for(int j = 0 ; j < s2; j++){
                m[i+1][j+1] = t1.charAt(i) != t2.charAt(j) ? Math.max(m[i][j+1], m[i+1][j]): m[i][j]+1; 
            }
        }
        
        return m[s1][s2]; 
    }
    
}
