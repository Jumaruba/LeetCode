from queue import PriorityQueue
class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        pq = PriorityQueue()
        for s in stones:
            pq.put(-s)
        while pq.qsize() > 1:
            s1 = pq.get()
            s2 = pq.get()
            pq.put(-s2+s1)
            
            
        return -pq.get()
    
