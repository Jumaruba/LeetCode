class Solution:
    
    def compress(self, chars: List[str]) -> int:

        self.np = 0         # new pointer: keeps track of the "new" array
        
        self.prev_char = chars[0]     # the current string being analysed.
        self.counter = 0        # how many curr_an there're until now
        
        
        for i, curr_char in enumerate(chars):
            if curr_char == self.prev_char:
                self.counter += 1
            else:
                self.new_pointer_compute(chars)
                self.counter = 1 
                self.prev_char = curr_char
            
        self.new_pointer_compute(chars)  
            
                
        return self.np
    
    def new_pointer_compute(self, chars):
        chars[self.np] = self.prev_char
        self.np += 1 
        if self.counter != 1 :
            self.write_counter(chars)
        
    def write_counter(self, chars): 
        counter_str = str(self.counter)
        for i, c in enumerate(counter_str): 
            chars[self.np] = c
            self.np += 1
                
            
        
