class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        curr_sum = 0
        for i,n in enumerate(nums):
            nums[i] = curr_sum + n
            curr_sum += n
            
        return nums
