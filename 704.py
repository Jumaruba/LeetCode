class Solution:
    def search(self, nums: List[int], target: int) -> int:
        nums_size = len(nums)
        l = 0
        r = nums_size-1 
        while(r >= l):
            m = (r - l)//2 + l
            if nums[m] < target: 
                l = m + 1 
            elif nums[m] > target: 
                r = m - 1 
            else: 
                return m 
            
        return -1
