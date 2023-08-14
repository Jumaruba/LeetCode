class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        l = max(nums)
        s = min(nums)
        size = l - s + 1
        arr = [0 for i in range(size)]  
        for i in nums:
            arr[i-s] +=1 
        c = 0
        for i in range(size-1, -1, -1):
            c += arr[i] 
            if c >= k:
                return i + s 

        return arr[0]
