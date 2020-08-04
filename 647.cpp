class Solution {
public:

    int countSubstrings(string s) {
        if (s.size() == 0) return 0 ; 
        if (s.size() == 1) return 1; 
        
        int total = 0;
        int begin, end; 
        for (int i= 0 ; i < s.size() ; i++){
            total ++; 
            begin  = i-1 ; 
            end = i+1; 
            while(begin >= 0 && end < s.size())    {
                if (s[begin] == s[end]) total ++; 
                else break; 
                begin --; 
                end ++; 
            }
            
            begin  = i ; 
            end = i+1; 
            while(begin >= 0 && end < s.size())    {
                if (s[begin] == s[end]) total ++; 
                else break; 
                begin --; 
                end ++; 
            }
            
        }
        return total ; 
    }
};
