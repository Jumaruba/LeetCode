class Solution:
    def incremovableSubarrayCount(self, nums: List[int]) -> int:
        size = len(nums)
        total = 0
        for i in range(size): 
            for j in range(i+1, size+1): 
                temp = nums[0:i] + nums[j:]
                if self.is_increasing(temp): 
                    total += 1 
        return total
            
    def is_increasing(self,nums):
        for i in range(1,len(nums)):
            if nums[i-1] >= nums[i]: 
                return False 
            
        return True 
            
        
