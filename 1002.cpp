class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        unordered_map<char, int> um; 
        unordered_map<char, int> currUm; 

        // Add first word to um. 
        for (int i = 0; i < words[0].size(); i++) {
            um[words[0][i]]++;
        }

        for (int i = 1; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                currUm[words[i][j]]++; 
            }
            for (auto it: currUm) cout << it.first << " " << it.second << endl ; 
            cout << endl;
            merge(currUm, um);
            currUm.clear(); 
        }

        vector<string> ans; 
        for (auto it: um) {
            for (int i = 0 ; i < it.second; i++)
                ans.push_back(string(1,it.first));
        }
        return ans; 
    }

    void merge(unordered_map<char, int>& currUm, unordered_map<char, int>& um){
        // Intersection. 
        for (auto it: currUm) {
            if (um.find(it.first) != um.end()) 
                um[it.first] = min(it.second, um[it.first]); 
        }
        // Remove the ones that are not in currUm. 
        unordered_map<char, int> umcopy = um;
        for (auto it: umcopy) {
            if (currUm.find(it.first) == currUm.end()) um.erase(it.first);
        }

        
    }
};
