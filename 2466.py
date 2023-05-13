class Solution:
    def countGoodStrings(self, low: int, high: int, zero: int, one: int) -> int:
        arr = [0 for i in range(high)] 
        MOD = 10 ** 9 + 7 
        total = 0   # the total different ways
        # setup 
        arr[one-1] = 1
        arr[zero-1] += 1
        for i in range(high): 
            if i - zero >= 0: 
                arr[i] += arr[i-zero]
            if i - one >= 0:
                arr[i] += arr[i-one]
            if i >= low-1: 
                total += (arr[i] % MOD) 
                total = total % MOD
        

        return total %MOD
