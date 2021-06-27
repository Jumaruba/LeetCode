class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> pascalTriangle = new ArrayList<>(); 
        if (numRows < 0) return pascalTriangle; 
        
        // Create first row. 
        pascalTriangle.add(List.of(1));
        // Add the other rows 
        for (int i = 2; i < numRows+1; i++){
            pascalTriangle.add(generateRowPascal(pascalTriangle.get(i-2), i)); 
        }
        
        return pascalTriangle; 
    } 
    
    public List<Integer> generateRowPascal(List<Integer> prevRow, int index){
        Integer prevRowSize = prevRow.size(); 
        List<Integer> currRow = new ArrayList<>(); 
        currRow.add(1); 
        for (int i = 0; i < prevRowSize-1; i++){
            currRow.add(prevRow.get(i) + prevRow.get(i+1)); 
        }
        currRow.add(1); 
        return currRow; 
    }
    
}
