class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        h = len(matrix)
        w = len(matrix[0])
        self.res = []
        self.matrix = matrix

        self.getSmaller(0, w, 0, h,0) 
        return self.res 
        
    def getSmaller(self, startW, endW, startH, endH, pos): 
        
        if pos == 0: 
            self.getTop(startW, endW, startH, endH)
            startH += 1
        elif pos == 1: 
            self.getRight(startW, endW, startH, endH)
            endW -= 1
        elif pos == 2:
            self.getBottom(startW, endW, startH, endH)
            endH -= 1
        elif pos==3:
            self.getLeft(startW, endW, startH, endH)
            startW += 1
            
        if endH-startH != 0 and endH > startH and endW > startW:  
            self.getSmaller(startW, endW, startH,  endH, (pos+1)%4)

    def getTop(self, startW, endW, startH, endH): 
        for i in range(startW, endW):
            self.res.append(self.matrix[startH][i])
            
    def getRight(self, startW, endW, startH, endH):
        for i in range(startH, endH):
            self.res.append(self.matrix[i][endW-1])
            
    def getBottom(self, startW, endW, startH, endH):
        for i in range(endW-1, startW-1, -1):
            self.res.append(self.matrix[endH-1][i])
            
    def getLeft(self, startW, endW, startH, endH):
        for i in range(endH-1, startH-1, -1):
            self.res.append(self.matrix[i][startW])
            
            
        
            
            
        
