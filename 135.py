class Solution:
    def candy(self, ratings: List[int]) -> int:
        self.result = [] 
        self.result = [1 for i in enumerate(ratings)]
        self.ratingsSize = len(ratings) 
        
        
        self.updateRightToLeft(ratings)
        self.updateLeftToRight(ratings)
        print(self.result)
        return sum(self.result)
    
    
    def updateRightToLeft(self, ratings):
        for i in range(1, self.ratingsSize): 
            if ratings[i] > ratings[i-1] and self.result[i] <= self.result[i-1]:
                self.result[i] = max(self.result[i-1] + 1, self.result[i]+1)
                
    def updateLeftToRight(self, ratings):
        for i in range(self.ratingsSize-2, -1, -1): 
            if ratings[i] > ratings[i+1] and self.result[i] <= self.result[i+1]:
                self.result[i] = max(self.result[i+1] +1, self.result[i]+1)
        
