class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        h = Counter(words)
        s = sorted(h.items(), key=lambda x: (-x[1], x[0]))
        return [s[i][0] for i in range(k)]
