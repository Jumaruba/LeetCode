class Solution:
    def rob(self, nums: List[int]) -> int:
        nums_size = len(nums)
        
        if nums_size == 1: 
            return nums[0] 
        
        prev = max(nums[1],nums[0])
        prevprev = nums[0] 
        
        for i in range(2, nums_size): 
            curr = max(prev, prevprev+nums[i])    
            prevprev = prev 
            prev = curr 
            
        return max(prev, prevprev) 

    
# Another solution 14/12/2022

class Solution:

    def rob(self, nums: List[int]) -> int:
        nums_size = len(nums)
        if nums_size <= 2:
            return max(nums)

        arr = [nums[0],nums[1],nums[0]+nums[2]]
        for i in range(3, nums_size):
            val = max(arr[0], arr[1]) + nums[i]
            arr[0] = arr[1]
            arr[1] = arr[2]
            arr[2] = val
        return max(arr
