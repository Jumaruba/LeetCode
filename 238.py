class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        m = 1
        size = len(nums)
        total_zeros = 0 
        for i in nums:
            if i == 0:
                total_zeros += 1
            if i != 0: 
                m *= i 

        for i in range(size):
            if total_zeros >= 2 or (total_zeros == 1 and nums[i] != 0):
                nums[i] = 0
            elif nums[i] == 0: 
                nums[i] = m
            else: 
                nums[i] = m//nums[i]

        return nums
