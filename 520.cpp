class Solution {
public:

    inline bool isCap(char &c) {
        return c - 'a' < 0; 
    }

    bool detectCapitalUse(string w) {
        if (w.size() == 1) return true; 
        bool cap = w[0] - 'a' < 0 && w[1] - 'a' < 0 ? true: false; 
        for (int i = 1; i < w.size() ;i++) { 
            if (cap && !isCap(w[i])) return false; 
            else if (!cap && isCap(w[i])) return false; 
        }
        return true; 
    }
};
