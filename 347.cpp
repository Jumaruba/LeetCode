//Given a non-empty array of integers, return the k most frequent elements.

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> umap;        // O(n) to store the frequency 
        vector<int> ans; 
        for (int i: nums) umap[i]++; 
        
        priority_queue<pair<int,int>> pq; 
        
        for (auto it = umap.begin(); it != umap.end(); it++){
            pq.push({it->second, it->first}); 
        }
        
        for (int i = 0 ; i < k; i++){
            ans.push_back(pq.top().second); 
            pq.pop(); 
        }
        
        return ans; 
    }
};