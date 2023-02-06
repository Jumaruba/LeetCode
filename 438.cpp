class Solution {
public:
    inline int toArr(char c){
        return int(c - 'a');
    }
    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size()) return {}; 
        vector<int> m(26,0);
        vector<int> o(26,0);
        vector<int> res; 
        int ps = p.size(); 
        for (char c: p) o[toArr(c)]++;

        for (int i = 0 ; i < p.size()-1; i++) m[toArr(s[i])]++;
        for (int i = ps -1 ; i < s.size(); i++){
            m[toArr(s[i])]++;
            if (m == o) res.push_back(i-(ps-1));
            m[toArr(s[i-(ps-1)])]--; 
        }

        return res; 
    }
};
