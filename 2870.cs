public class Solution {
    public int MinOperations(int[] nums) {
        var dict = new Dictionary<int, int>(); 
        var res = 0; 
        foreach (var i in nums) {
            if (dict.ContainsKey(i))
                dict[i] += 1; 
            else 
                dict[i] = 1; 
        }

        foreach (var key in dict.Keys){
            var value = dict[key]; 
            var mod3 = value % 3; 
            
            if (value == 1) return -1; 
            else if (mod3 == 0) res += value / 3; 
            else if (mod3 == 2) res += (value - 2)/ 3 + 1; 
            else if (mod3 == 1) res += (value - 4)/3 + 2; 
        }

        return res; 
    }
}
