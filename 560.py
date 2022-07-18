class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        nums_size = len(nums)
        self.hash_ = {}
        curr_sum = 0
        total = 0
        
        for index, number in enumerate(nums): 
            curr_sum += number 
            complement_times = self.getComplement(curr_sum, k)
            if curr_sum == k: 
                total += 1 
            total += complement_times 
            self.addToHash(curr_sum)
            
        return total 
            
            
        
        
    def getComplement(self, curr_number, k): 
        complement = curr_number - k
        if complement not in self.hash_:
            return 0 
        return self.hash_[complement]
    
    def addToHash(self, curr_sum): 
        if curr_sum not in self.hash_.keys():
            self.hash_[curr_sum] = 1 
        else: 
            self.hash_[curr_sum] += 1 
        
