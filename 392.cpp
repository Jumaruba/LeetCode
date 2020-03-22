class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.size() == 0) return true; 
        bool have = false; 
        size_t s_size = s.size(); 
        size_t marker = 0; 
        for (char c: t){
            if (c == s[marker]){
                marker++; 
                if (marker == s_size) return true; 
            }
    
        }
        return false; 
            
        
    }
};
