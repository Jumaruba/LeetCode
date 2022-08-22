class Solution:
    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
        num_sum = sum(nums)
        if num_sum % k != 0:
            return False 
        
        N = len(nums)
        has_cache = [False] * (1 << N)
        cache = [None] * (1 << N)
        
        k_sum = num_sum//k 
        
        nums.sort(reverse=True)
        
        def can_partition(mask, curr_sum=0, count=0): 
            # The last sum must have the right sum 
            if count == k-1: 
                return True
            
            # Saying that we have already a value. 
            if has_cache[mask]:
                return cache[mask]
            
            if curr_sum == k_sum:
                return can_partition(mask, 0, count+1) 
            elif curr_sum > k_sum:
                return False
                
            has_cache[mask] = True             
            # Visit each number 
            for i in range(N): 
                # Checking if the number is in the mask 
                if mask & (1 << i) == 0:
                    if can_partition((mask | 1 << i), curr_sum + nums[i], count):
                        cache[mask] = True 
                        return True
            cache[mask] = False 
            return False 


        return can_partition(0)
