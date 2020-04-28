class Solution {
public:
    
    int lastStoneWeight(vector<int>& stones) {
        while(stones.size() > 1){
            auto it = max_element(stones.begin(), stones.end()); 
            int max = *it; 
            stones.erase(it); 
            it = max_element(stones.begin(), stones.end()); 
            int max_2 = *it;  
            stones.erase(it); 
            int result = abs(max - max_2); 
            if (result) { 
                stones.emplace_back(result); 
            } 
        
        } 
        if (stones.empty()) return 0; 
        return stones[0]; 
        
        
    }
};
