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
