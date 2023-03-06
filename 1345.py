class Solution:
    def minJumps(self, arr: List[int]) -> int:
        self.h = defaultdict(list)
        for i,v in enumerate(arr):
            self.h[v].append(i)
        return self.bfs(len(arr)-1, arr)

    def bfs(self, target, arr):
        visited = set([-1,0])
        q = set([0])
        level = 0

        while q:
            tmp = set([])
            for pos in q: 
                if pos == target:
                    return level
                visited.add(pos)                # position already visited
                num = arr[pos]                  # the current number
                neighbors = set(self.h[num])    # elements to be visited
                # merge elements not visited yet
                tmp |= (neighbors | set([pos+1, pos-1]))-visited
                self.h[num] = []    # clean the hashmap

            q = tmp
            level += 1
        return level
