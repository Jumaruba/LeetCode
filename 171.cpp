class Solution {
public:
    int titleToNumber(string& s) {
        if (s.size()== 0) return 0; 
        string aux(s.begin() +1 , s.end());
        return pow(26, s.size()-1) * (s[0] - 64) + titleToNumber(aux); 
    }
};
