public class Solution {
    public int NumberOfBeams(string[] bank) {
        var prevLazers = 0; 
        var currLazers = 0; 
        var total = 0; 

        foreach (var str in bank) {
            foreach (var c in str) {
                if (c == '1') currLazers += 1; 
            }
            if (currLazers != 0){
                total += (currLazers*prevLazers); 
                prevLazers = currLazers;
                currLazers = 0;
            }
        }

        return total; 
    }
}
