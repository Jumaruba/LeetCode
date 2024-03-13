public class Solution {
    public int PivotInteger(int n) {
        int left = 0, right = (n + 1)*n/2, pivot = 1;
        for (var i = 0; i < n; i++) {
            right -= pivot;
            if (right == left) return pivot;
            left += pivot;
            pivot++;
        }
        return -1;
    }
}
