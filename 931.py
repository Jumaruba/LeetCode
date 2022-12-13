class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        matrix_cols = len(matrix[0])
        if matrix_cols == 1:
            return matrix[0][0]
        prev_line = [0 for _ in range(matrix_cols)]

        for i in matrix:
            aux = []
            for j, val in enumerate(i): 
                aux.append(self.get_prev(prev_line, val, j, matrix_cols))
            prev_line = aux

        return min(prev_line)

    def get_prev(self, prev_line, curr_val, pos, size_cols): 
        if pos == 0:
            return min(prev_line[pos], prev_line[pos+1]) + curr_val
        elif pos == size_cols-1: 
            return min(prev_line[pos], prev_line[pos-1]) + curr_val
        else:
            return min([prev_line[pos-1], prev_line[pos], prev_line[pos+1]]) + curr_val
