class Solution {
    public String removeDuplicates(String s) {
        StringBuilder builder = new StringBuilder(s); 
        
        for (int i = 0 ; i < builder.length()-1; i++){
            if (i < 0) i = 0; 
            if (builder.length() == 1) return builder.toString(); 
            if (builder.charAt(i) == builder.charAt(i+1)) {
                builder.deleteCharAt(i+1);
                builder.deleteCharAt(i); 
                i -=2; 
            }
        }
        
        return builder.toString(); 
    }
    

}