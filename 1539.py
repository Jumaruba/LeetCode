class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        c = 1
        for i in arr:
            if i - c < k:
                k -= i-c-1
                c = i 
            elif i-c >= k:
                return c + k-1

        return c+k-1
