class Solution:
    def longestPalindrome(self, s: str) -> int:
        h = collections.defaultdict(int)
        
        for letter in s:
            h[letter] += 1
        
        
        max_even = self.get_max_even(h)
        sum_all_pairs = self.get_sum_all_pairs(h, max_even)
        return h[max_even] + sum_all_pairs
    
    def get_max_even(self, h):
        max_even_count = 0
        letter = ''
        for key, value in h.items():
            if value % 2:
                max_even = max(max_even_count, value)
                letter = key
            
        return letter
    
    def get_sum_all_pairs(self, h, max_even): 
        pairs_all_sum = 0
        for key,value in h.items():
            if key != max_even:
                if value % 2:
                    pairs_all_sum += value-1
                else:
                    pairs_all_sum += value
                
        return pairs_all_sum
    
