public class Solution {
    public int LongestConsecutive(int[] nums) {
        HashSet<int> set = new HashSet<int>(); 
        var maxSize = 0; 
        foreach (var num in nums) {
            set.Add(num);
        }

        foreach (var num in nums){
            var target = num; 
            var size =  1; 
            while(set.Contains(target+1)) {
                size += 1; 
                target += 1; 
                set.Remove(target); 
            }
            target = num; 
            while(set.Contains(target-1)){
                size += 1;
                target -= 1;  
                set.Remove(target); 
            }
            maxSize = Math.Max(size, maxSize); 
        }
        return maxSize; 
    }
}
