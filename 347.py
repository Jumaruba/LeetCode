class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        self.frequencyDict = {}
        for element in nums:
            self.addToHash(element)
        
        self.createTupleArr()
        self.sortDescArr()
        return self.getKTopFrequent(k)
        
    def addToHash(self,element):
        self.frequencyDict[element] = self.frequencyDict.get(element, 0) + 1
        
    def createTupleArr(self):
        self.tupleArr = []
        for key in self.frequencyDict.keys():
            self.tupleArr.append((self.frequencyDict[key], key))
            
        
    def sortDescArr(self):
        self.tupleArr = sorted(self.tupleArr, reverse=True)
        
    def getKTopFrequent(self, k):
        topFrequent = []
        for i in range(k): 
            topFrequent.append(self.tupleArr[i][1])
            
        return topFrequent
