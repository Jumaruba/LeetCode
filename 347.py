class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        c = list(dict(Counter(nums)).items())
        c.sort(key=lambda x: x[1], reverse=True)
        return [i[0] for i in c][:k]
