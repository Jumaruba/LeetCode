class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> umap; 
        for (char i: s) umap[i] ++; 
        
        priority_queue<pair<int, char>> pq; 

        for (auto it = umap.begin() ; it != umap.end(); it++) pq.push({it->second, it->first});
        
        int counter = 0; 
        string ans; 
        while(counter < s.size()){  
            for (int i = 0 ; i < pq.top().first; i++){
                ans+= pq.top().second; 
                counter ++; 
            }
            pq.pop(); 
        }
        return ans; 
    }
};
