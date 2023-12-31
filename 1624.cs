public class Solution {
    public int MaxLengthBetweenEqualCharacters(string s) {
        // Char to Position 
        var dict = new Dictionary<char, int>(); 
        var maxDist = -1; 
        for (var i= 0; i < s.Length; i++) {
            if (dict.ContainsKey(s[i])) {
                maxDist = Math.Max(maxDist, i - dict[s[i]] - 1); 
                continue;
            } 
            dict[s[i]] = i; 
        }

        return maxDist; 
    }
}
