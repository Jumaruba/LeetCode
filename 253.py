class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        self.splitIntervals = []
        self.currNumRoom = 0 
        self.maxNumRoom = 0
        
        for index, [start, end] in enumerate(intervals):
            self.splitIntervals.append([start, 1, index])
            self.splitIntervals.append([end, 0, index])
        
        self.splitIntervals = sorted(self.splitIntervals)
        print(self.splitIntervals)
        for event in self.splitIntervals:
            if event[1] == 1:
                self.currNumRoom +=1
                self.maxNumRoom = max(self.currNumRoom, self.maxNumRoom)
            else:
                self.currNumRoom -= 1
                
        return self.maxNumRoom

