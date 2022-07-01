class Solution:
    def maximumUnits(self, box_types: List[List[int]], truck_size: int) -> int:
        box_types = sorted(box_types, key=lambda box: -box[1])
        total_elements = 0
        for index, (num_boxes, num_elements) in enumerate(box_types):
            new_truck_size = max(truck_size - num_boxes, 0)
            used_boxes = truck_size - new_truck_size 
            truck_size = new_truck_size
            total_elements += used_boxes*num_elements
        return total_elements
            
