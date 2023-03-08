class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        if len(piles) == 1:
            return int(ceil(piles[0]/h))

        def get_hours(k: int):
            return sum(list(map(lambda x: ceil(x/k), piles)))

        mx = max(piles)
        mn = 1
        m = ceil((mx-mn)/2 + mn)
        while mn+1 < mx: 
            m = ceil((mx-mn)/2 + mn)
            curr_h = get_hours(m)
            if curr_h <= h:
                mx = m
            elif curr_h > h:
                mn = m+1

        h_mn = get_hours(mn)
        h_mx = get_hours(mx)
        if h_mn <= h:
            return mn
        return mx
