class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        h = collections.defaultdict(int)
        
        for i,n in enumerate(nums):
            complement = target - n
            if h[complement] != 0:
                return [h[complement], i] 
            elif nums[0] == complement and i != 0:
                return [0, i]
            h[n] = i 
        
        return [0,0]
            
