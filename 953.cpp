class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> m; 
        for (int i = 0; i < order.size(); i++) m[order[i]] = i; 

        for (int i = 1; i < words.size(); i++){
            if (isHigherThan(words[i-1], words[i], m)) return false; 
        }
        return true; 
    }

    bool isHigherThan(string& s1, string& s2, unordered_map<char,int> &m){
        int size = min(s1.size(), s2.size());
        for (int i = 0 ; i< size; i++){
            if (m[s1[i]] > m[s2[i]]) return true; 
            else if (m[s1[i]] < m[s2[i]]) return false; 
        }

        return s1.size() > s2.size(); 
    }
};
