class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        elem_1 = cost[1]    # curr_pos - 1 
        elem_2 = cost[0]    # curr_pos - 2 
        
        cost_size = len(cost)
        
        for i in range(2, cost_size): 
            aux = elem_1
            elem_1 = min(elem_1, elem_2) + cost[i]
            elem_2 = aux 
            
        return min(elem_1, elem_2)
        
        
