# How sillyyy
class Solution:
    def isUgly(self, n: int) -> bool:
        return n > 0 and (2**20 * 3**20 * 5**14) % n == 0
