class Solution {
public:
    //acha o maior numero, move todas para lá 
    //pre
    int minCostToMoveChips(vector<int>& chips) {
        int total = 10000; 
        int new_total = 0; 
        auto max = max_element(chips.begin(), chips.end()); 
        for (auto ele = chips.begin(); ele < chips.end(); ele++){
            for (auto it = chips.begin(); it < chips.end(); it++){
                if ( ((*it) - (*ele)) % 2 ) new_total++; 
            }
            if (new_total < total) total = new_total; 
            new_total = 0; 
        }
        return total; 
    }
};
