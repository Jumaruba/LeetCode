class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        
        bulls = self.getBulls(secret, guess)
        cows = self.getCows(secret, guess)
        
        return str(bulls) + "A" + str(cows-bulls) + "B"
        
    def getBulls(self, secret, guess):
        bulls = 0
        for i, l in enumerate(secret):
            if l == guess[i]:
                bulls += 1
        return bulls
    
    def getCows(self, secret, guess):
        cows = 0 
        hSecret = Counter(secret)
        hGuess = Counter(guess)
        
        for k, v in hGuess.items():
            if hSecret[k] != 0:
                cows += min(v, hSecret[k])
        
        return cows
        
