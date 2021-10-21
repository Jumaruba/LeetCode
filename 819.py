class Solution:
    def mostCommonWord(self, p: str, banned: List[str]) -> str: 
        p = re.sub(r'[!|\?||\'|,|\.|;| ]+', ' ', p)
        w = p.split(" ")
        dict = {}

        bestUntilNow = -1
        bestWord = ''
        for b in banned: 
            dict[b.lower()] = -1
        for s in w:
            s = s.lower()
            if s in dict:
                if dict[s] == -1:
                    continue
                else:
                    dict[s] += 1
            else:
                dict[s] = 1
            if dict[s] > bestUntilNow:
                bestWord = s 
                bestUntilNow = dict[s]

        return bestWord