class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        buy = prices[0]
        sell = prices[0]
        best = 0
        for p in prices: 
            if p < buy:
                buy = p
                sell = p
            sell = max(sell, p)
            best = max(best, sell-buy)
            
        return best 
