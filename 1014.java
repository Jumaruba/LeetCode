class Solution {
    public int maxScoreSightseeingPair(int[] values) {
        int b =  values[0], m = 0, pb, n = values.length; 
        for (int i = 1; i < n; i++){
            pb = b; 
            b = Math.max(values[i] + i, b); 
            m = Math.max(pb + values[i] - i, m); 
        }
        
        return m; 
    }
}
