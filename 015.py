class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        self.nums_size = len(nums)      

        if self.nums_size < 3: 
            return []
        
        self.target_sum = -nums[0] 
        self.result = set({})
        self.nums = nums
        
        for i,number in enumerate(nums):
            self.target_sum = -number
            self.findPair(i)
        
        result_size = len(self.result)
        result_array = []
        for i, tup in enumerate(self.result):
            result_array.append(list(tup))
        
        return result_array
            
    def findPair(self,curr_index):
        hash_set = set({})
        for i in range(curr_index+1, self.nums_size): 
            curr_number = self.nums[i]
            target_complement = self.target_sum - curr_number
            
            if target_complement not in hash_set: 
                hash_set.add(curr_number)
            else:
                array_res = sorted([-self.target_sum, curr_number, target_complement])
                self.result.add(tuple(array_res))
