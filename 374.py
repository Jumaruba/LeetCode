class Solution:
    def guessNumber(self, n: int) -> int:
        l = 1 
        while l <= n: 
            mid = (n-l)//2 + l 
            if guess(mid) == 0: 
                return mid 
            elif guess(mid) == 1: 
                l = mid + 1
            elif guess(mid) == -1: 
                n = mid - 1 

        return 1
