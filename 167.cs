// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/ 

public class Solution {
    public int[] TwoSum(int[] numbers, int target) {
        int rp = 0, lp = numbers.Length-1;
        while(lp > rp) {
            if (numbers[lp] + numbers[rp] == target) 
                return new int[]{rp+1, lp+1}; 
            else if (numbers[lp] + numbers[rp] > target)
                lp -= 1; 
            else 
                rp += 1; 
        } 

        return new int[]{rp+1, lp+1}; 
    }
}
