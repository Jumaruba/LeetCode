class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        s = len(nums)
        return (s + 1)*s //2 - sum(nums)
