class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        if len(piles) == 1:
            return int(ceil(piles[0]/h))

        def can_eat(k: int):
            return sum(list(map(lambda x: ceil(x/k), piles))) <= h

        mx = max(piles)
        mn = 1
        while mn < mx: 
            m = (mx-mn)//2 + mn
            ce = can_eat(m)
            if ce:
                mx = m
            else:
                mn = m+1

        return mn
